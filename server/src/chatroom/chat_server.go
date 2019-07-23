package chatroom

import (
	"bytes"
	"encoding/json"
	"io/ioutil"
	"net"
	"strconv"
	"strings"
	"time"
)

const (
	LISTEN_TCP = "tcp"
	PING_MSG   = "receive connection from "
)

//ChatServer data structure of server
type ChatServer struct {
	listenAddr string
	status     bool
	listener   net.Listener
}

//user type
type userType struct {
	Name  string
	Pwd   string
	Level int
	Money int
	IsVIP bool
}

//login type
type loginType struct {
	id     string
	conn   net.Conn
	status bool
}

//A dict
var userMap = make(map[string]userType)
var loginMap = make(map[int]loginType)

//Awesome Variables
var imgCode = 1000

//NewChatServer create a new server, you should explain why we do this
func NewChatServer(addr string, port int) *ChatServer {
	server := new(ChatServer)
	server.listenAddr = addr + ": " + strconv.Itoa(port)
	return server
}

//SaveUserInfo saves users' information.
func SaveUserInfo() {
	//Write Into File
	result, _ := json.MarshalIndent(userMap, "", "   ")
	PrintLog(string(result))
	ioutil.WriteFile("./user_info.dat", []byte(result), 0777)
}

//CreateSuperUser Creates super users.
func CreateSuperUser() {
	var admin userType
	admin.Level = 10
	admin.Money = 99999
	admin.Name = "管理员"
	admin.Pwd = "admin"
	admin.IsVIP = true

	userMap["admin"] = admin
}

//SpreadAd Ads
func SpreadAd() {
	for {
		time.Sleep(10 * time.Second)
		msgToSend := "255,0,0|[VIP会员中心]: VIP充值享特权，免广告，双倍积分，尊贵身份标识，现在仅需 199金币！\n"

		//Sending...
		for _, conn := range loginMap {
			if !userMap[conn.id].IsVIP && conn.status {
				SendClientMsg(conn.conn, "msg", msgToSend)
			}
		}
	}
}

//spreadMsg Msgs
func spreadMsg(thisID int, msg string) {
	msgToSend := userMap[loginMap[thisID].id].Name
	if userMap[loginMap[thisID].id].IsVIP {
		msgToSend += "(VIP会员)"
		msgToSend = "255,0,0|" + msgToSend
	} else {
		msgToSend = "0,0,0|" + msgToSend
	}
	msgToSend += " " + GetCurrentTimeString() + ":\n"
	msgToSend += msg + "\n"

	//Sending...
	for _, conn := range loginMap {
		go SendClientMsg(conn.conn, "msg", msgToSend)
	}
}

//ImgSpreadMsg img spread msgs.
func ImgSpreadMsg(client net.Conn, thisID int) {
	msgToSend := userMap[loginMap[thisID].id].Name
	if userMap[loginMap[thisID].id].IsVIP {
		msgToSend += "(VIP会员)"
		msgToSend = "255,0,0|" + msgToSend
	} else {
		msgToSend = "0,0,0|" + msgToSend
	}
	msgToSend += " " + GetCurrentTimeString() + ":"
	//Sending...
	SendClientMsg(client, "msg", msgToSend)
}

//StartListen main server function
func (server ChatServer) StartListen() {
	CreateSuperUser()
	//LoadUser
	if result, err := ioutil.ReadFile("./user_info.dat"); err == nil {
		json.Unmarshal(result, &userMap)
		PrintLog("Load user data successfully!")
	} else {
		PrintErr("Load user data failed!")
	}
	//User ID
	user_id := 1000
	//start listen on the address given
	listener, err := net.Listen(LISTEN_TCP, server.listenAddr)
	server.listener = listener

	//exit when server listen fail
	if err != nil {
		PrintErr(err.Error())
	} else {
		PrintLog("Start Listen " + server.listenAddr)
	}

	//Begin to spread ads.
	go SpreadAd()
	//main server loop, you should explain how this server loop works
	for {
		client, acceptError := server.listener.Accept() //when a user comes in
		if acceptError != nil {
			PrintErr(acceptError.Error()) //if accept go wrong, then the server will exit
			break
		} else {
			user_id++
			PrintClientMsg("User Login:" + strconv.Itoa(user_id))
			var tmp loginType
			tmp.conn = client
			tmp.status = false
			loginMap[user_id] = tmp
			go server.userHandler(client, user_id)
		}
	}
}

func login(client net.Conn, thisID int) bool {
	var username, password string
	this_login := loginMap[thisID]
	login_status := 0
	buffer := make([]byte, 1024)
	clientAddr := client.RemoteAddr()

	var msg string
	for {
		readSize, readError := client.Read(buffer)
		if readError != nil {
			PrintErr(clientAddr.String() + " quit the chat room!")
			client.Close()
			return false
		} else {
			msg = string(buffer[0:readSize])
			PrintClientMsg(strconv.Itoa(thisID) + ":" + msg)
			if login_status == 0 {
				username = msg
				login_status = 1
			} else if login_status == 1 {
				password = msg
				login_status = 2
				break
			}
		}
	}
	if login_status == 2 {
		if value, ok := userMap[username]; ok {
			if value.Pwd == password {
				this_login.id = username
				this_login.status = true
				loginMap[thisID] = this_login
				SendClientMsg(client, "~@login_success", "")
				return true
			}
			SendClientMsg(client, "~@login_pwd_error", "")
		} else {
			SendClientMsg(client, "~@login_no_such_user:", "")
		}
	}
	return false
}

func createUser(client net.Conn, thisID int) bool {
	var username, Name, password string
	step := 0

	buffer := make([]byte, 1024)      //create a buffer
	clientAddr := client.RemoteAddr() //get user's address
	var msg string
	for { //main serve loop
		readSize, readError := client.Read(buffer)
		if readError != nil {
			PrintErr(clientAddr.String() + " quit the chat room!") //if read error occurs, close the connection with user
			client.Close()
			return false
		} else {
			msg = string(buffer[0:readSize])                 //or convert the byte stream to a string
			PrintClientMsg(strconv.Itoa(thisID) + ":" + msg) //then print the message
			if step == 0 {
				username = msg
				if _, ok := userMap[username]; ok {
					SendClientMsg(client, "~@create_username_used", "")
					return false
				}
				step = 1
			} else if step == 1 {
				password = msg
				step = 2
			} else if step == 2 {
				Name = msg
				step = 3
				break
			}
		}
	}

	var user_tmp userType
	user_tmp.Name = Name
	user_tmp.Pwd = password
	user_tmp.Level = 1
	user_tmp.Money = 0
	user_tmp.IsVIP = false

	userMap[username] = user_tmp
	SendClientMsg(client, "~@create_success", "")
	return true
}

func showUserStatus(client net.Conn, thisID int) {
	curMoney := userMap[loginMap[thisID].id].Money
	curLevel := userMap[loginMap[thisID].id].Level
	curName := userMap[loginMap[thisID].id].Name
	msgToSend := curName + "已经进入聊天室，等级" + strconv.Itoa(curLevel) + "，金币" + strconv.Itoa(curMoney)
	SendClientMsg(client, "status", msgToSend)
}

func updateUserInfo(client net.Conn, thisID int) {
	curInfo := userMap[loginMap[thisID].id]
	curInfo.Money++
	userMap[loginMap[thisID].id] = curInfo
	SaveUserInfo()
}

//SpecialMsg processes special messages.
func SpecialMsg(msg string, client net.Conn, thisID int) bool {
	if strings.HasPrefix(msg, "name:") {
		pre := 5
		comma := strings.Index(msg[pre:], ":") + pre
		length, _ := strconv.Atoi(msg[pre:comma])
		afterName := string(([]rune(msg))[comma+1 : comma+length+1])
		userData := userMap[loginMap[thisID].id]
		if userData.Money < 10 {
			SendClientMsg(client, "msgbox", "对不起，您的金币不足！")
		} else {
			userData.Money -= 10
			userData.Name = afterName
			userMap[loginMap[thisID].id] = userData
			SendClientMsg(client, "msgbox", "昵称修改成功！")
			showUserStatus(client, thisID)
			SaveUserInfo()
		}
		return true
	} else if strings.HasPrefix(msg, "msg:") {
		pre := 4
		comma := strings.Index(msg[pre:], ":") + pre
		length, _ := strconv.Atoi(msg[pre:comma])
		afterMsg := string(([]rune(msg))[comma+1 : comma+length+1])
		spreadMsg(thisID, afterMsg)
		updateUserInfo(client, thisID)
		showUserStatus(client, thisID)
		SaveUserInfo()
		return true
	} else if strings.HasPrefix(msg, "img:") {
		length, _ := strconv.Atoi(msg[4:])

		buffer := make([]byte, length+1024) //create a buffer
		clientAddr := client.RemoteAddr()   //get user's address

		for { //main serve loop
			readSize, readError := client.Read(buffer)
			if readError != nil {
				PrintErr(clientAddr.String() + " quit the chat room!")
				spreadMsg(thisID, "退出了聊天室")
				delete(loginMap, thisID)
				client.Close()
				break
			} else {
				//Write in
				var buff bytes.Buffer
				buff.Write([]byte("img_" + strconv.Itoa(imgCode) + ".jpg|"))
				buff.Write(buffer[:readSize])

				for _, conn := range loginMap {
					ImgSpreadMsg(client, thisID)
					go SendClientContent(conn.conn, "img", buff.Bytes())
				}
				//client.Write(buff.Bytes())
				ioutil.WriteFile("./test.png", buffer[:readSize], 0777)
				imgCode++
				break
			}
		}
		return true
	}
	return false
}

func (server ChatServer) userHandler(client net.Conn, thisID int) {
	login_status := false
	buffer := make([]byte, 1024)      //create a buffer
	clientAddr := client.RemoteAddr() //get user's address
	var msg string
	PrintClientMsg(PING_MSG + clientAddr.String()) //print a log to show that a new client comes in

	for { //main serve loop
		readSize, readError := client.Read(buffer)
		if readError != nil {
			PrintErr(clientAddr.String() + " quit the chat room!")
			spreadMsg(thisID, "退出了聊天室")
			delete(loginMap, thisID)
			client.Close()
			break
		} else {
			msg = string(buffer[0:readSize])
			PrintClientMsg(strconv.Itoa(thisID) + ":" + msg)
			if !login_status {
				if msg == "~@Client:Login" {
					if login(client, thisID) == true {
						spreadMsg(thisID, "进入了聊天室。")
						login_status = true
						showUserStatus(client, thisID)
					}
				} else if msg == "~@Client:Create" {
					if createUser(client, thisID) == true {
						SaveUserInfo()
					}
				}
			} else {
				SpecialMsg(msg, client, thisID)
			}
		}
	}
}
