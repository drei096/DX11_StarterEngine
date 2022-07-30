#pragma once
#include "CustomWindowsH.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <memory>

class Window
{
private:
	// singleton manages registration/cleanup of window class
	class WindowClass
	{
	public:
		static LPCWSTR GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static constexpr LPCWSTR wndClassName = L"DX11 Engine Window Class";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};

public:
	Window(int width, int height, LPCWSTR name) noexcept;
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	static std::optional<int> ProcessMessages() noexcept;
	void SetTitle(const std::string& title);
	Graphics& GetGrapx(); 

private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

private:
	int width;
	int height;
	HWND hWnd;

public:
	Keyboard kbd;
	Mouse mouse;
	std::unique_ptr<Graphics> pGrapx;
};

