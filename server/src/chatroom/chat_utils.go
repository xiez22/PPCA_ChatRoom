package chatroom

import (
	"bytes"
	"fmt"
	"net"
	"strconv"
	"time"
	"unicode/utf8"
)

//something about color, no need modifying
const (
	CHAT_LOG    = "[LOG %s] %s\n"
	CHAT_ERR    = "[ERR %s] %s\n"
	CHAT_MSG    = "[MSG %s] %s\n"
	COLOR_RED   = "\033[31m"
	COLOR_GREEN = "\033[32m"
	COLOR_RESET = "\033[0m"
)

//GetCurrentTimeString get current time and return a string
func GetCurrentTimeString() string {
	return time.Unix(time.Now().Unix(), 0).Format("2006/01/02 15:04:05")
}

//PrintLog print a log info
func PrintLog(msg string) {
	fmt.Printf(CHAT_LOG, GetCurrentTimeString(), msg)
}

//PrintErr print an error info
func PrintErr(msg string) {
	fmt.Printf(COLOR_RED+CHAT_ERR+COLOR_RESET, GetCurrentTimeString(), msg)
}

//PrintClientMsg print message receive from some client
func PrintClientMsg(msg string) {
	fmt.Printf(COLOR_GREEN+CHAT_MSG+COLOR_RESET, GetCurrentTimeString(), msg)
}

//SendClientMsg print a log
func SendClientMsg(conn net.Conn, msgType string, content string) {
	PrintLog(msgType + ":" + strconv.Itoa(utf8.RuneCountInString(content)) + ":" + content)
	SendClientContent(conn, msgType, []byte(content))
}

//SendClientContent sends content with the standard format: @size:op!content
func SendClientContent(conn net.Conn, msgType string, content []byte) {
	var allContent bytes.Buffer
	length := len([]byte(msgType+"!")) + len(content)
	allContent.Write([]byte("@" + strconv.Itoa(length) + ":"))
	allContent.Write([]byte(msgType + "!"))
	allContent.Write(content)
	conn.Write(allContent.Bytes())
}
