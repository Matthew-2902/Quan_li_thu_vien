#pragma once
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>

#define Enter 13
//const int WHITE=15;
#define PASSWORD "abcdef"
//const int WHITE=15;
 
char* Pwd () { 
     char S[40]; int i=0;
     while ((S[i]= getch()) != Enter ) 
     { printf ("%c", '*') ; i++ ; 
     }
     S[i]='\0';
     return S;
}
int CheckPwd () {
    int dem =0; 
    for ( dem =1 ; dem <=3 ; dem++)
    { printf( "Password :"); 
      if (strcmp(Pwd(),PASSWORD) ==0)   return 1;
      else printf ( "\nPassword sai. Hay nhap lai\n")  ; 
    }
    return 0;  
}

void gotoxy(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

int wherex( void )
{
    HANDLE hConsoleOutput;  
    
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol( ) {// xóa từ vị trí con trỏ hiện tại đến hết dòng bên phải.
COORD coord;
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
coord.X = info.dwCursorPosition.X;
coord.Y = info.dwCursorPosition.Y;
FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
gotoxy (info.dwCursorPosition.X , info.dwCursorPosition.Y );
}

void SetColor(WORD color)//chuyển tất cả màu của chữ từ hàm này về sau sang màu.
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)// chuyển màu của nền.
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clrscr() {
	system("cls");
}

// các màu ném cho kiểu dữ liệu WORD
// màu chữ.
// FOREGROUND_BLACK	0x0000	Đen
// FOREGROUND_BLUE	0x0001	Xanh dương
// FOREGROUND_GREEN	0x0002	Xanh lá
// FOREGROUND_CYAN	0x0003	Xanh ngọc
// FOREGROUND_RED	0x0004	Đỏ
// FOREGROUND_MAGENTA	0x0005	Tím
// FOREGROUND_YELLOW	0x0006	Vàng
// FOREGROUND_GRAY	0x0007	Xám
// FOREGROUND_INTENSITY	0x0008	Tăng độ sáng
// nền
// BACKGROUND_BLACK	0x0000	Đen
// BACKGROUND_BLUE	0x0010	Xanh dương
// BACKGROUND_GREEN	0x0020	Xanh lá
// BACKGROUND_CYAN	0x0030	Xanh ngọc
// BACKGROUND_RED	0x0040	Đỏ
// BACKGROUND_MAGENTA	0x0050	Tím
// BACKGROUND_YELLOW	0x0060	Vàng
// BACKGROUND_GRAY	0x0070	Xám
// BACKGROUND_INTENSITY	0x0080	Tăng độ sáng nền


