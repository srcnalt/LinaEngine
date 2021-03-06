/*
Author: Inan Evin
www.inanevin.com

Copyright 2018 Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions
and limitations under the License.

Class: IMGUILayer
Timestamp: 3/7/2019 1:58:49 PM

*/

#include "LinaPch.hpp"
#include "IMGUI/IMGUILayer.hpp"  
#include "Utility/imgui/imgui.h"
#include "Input/InputMappings.hpp"
#include "Core/Application.hpp"

#include "Rendering/Window.hpp"

#ifdef LINA_GRAPHICS_OPENGL

#include "PackageManager/OpenGL/GLIMGUI.hpp"

#endif

#include "GLFW/glfw3.h"

namespace LinaEngine
{
	IMGUILayer::IMGUILayer() : Layer("IMGUILayer")
	{

	}

	IMGUILayer::~IMGUILayer()
	{

	}

	void IMGUILayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.KeyMap[ImGuiKey_Tab] = LINA_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = LINA_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = LINA_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = LINA_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = LINA_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = LINA_KEY_PAGEUP;
		io.KeyMap[ImGuiKey_PageDown] = LINA_KEY_PAGEDOWN;
		io.KeyMap[ImGuiKey_Home] = LINA_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = LINA_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = LINA_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = LINA_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = LINA_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = LINA_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = LINA_KEY_RETURN;
		io.KeyMap[ImGuiKey_Escape] = LINA_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A] = LINA_KEY_A;
		io.KeyMap[ImGuiKey_C] = LINA_KEY_C;
		io.KeyMap[ImGuiKey_V] = LINA_KEY_V;
		io.KeyMap[ImGuiKey_X] = LINA_KEY_X;
		io.KeyMap[ImGuiKey_Y] = LINA_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = LINA_KEY_Z;

#ifdef LLF_GRAPHICS_OPENGL

		ImGui_ImplOpenGL3_Init();

#endif
		

	}

	void IMGUILayer::OnDetach()
	{
	}

	void IMGUILayer::OnUpdate()
	{

#ifdef LLF_GRAPHICS_OPENGL

	

		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		//io.DisplaySize = ImVec2(app.GetRenderingEngine().GetMainWindow().GetWidth(), app.GetRenderingEngine().GetMainWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	
#endif

	
	}

	void IMGUILayer::OnEvent(Event & e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseButtonPressedEvent>(LINA_BIND_EVENT_FN(IMGUILayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(LINA_BIND_EVENT_FN(IMGUILayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(LINA_BIND_EVENT_FN(IMGUILayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(LINA_BIND_EVENT_FN(IMGUILayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressedEvent>(LINA_BIND_EVENT_FN(IMGUILayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(LINA_BIND_EVENT_FN(IMGUILayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(LINA_BIND_EVENT_FN(IMGUILayer::OnKeyTypedEvent));
		dispatcher.Dispatch<WindowResizeEvent>(LINA_BIND_EVENT_FN(IMGUILayer::OnWindowResizeEvent));

	}

	bool IMGUILayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		return false;
	}

	bool IMGUILayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool IMGUILayer::OnMouseMovedEvent(MouseMovedEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		return false;
	}

	bool IMGUILayer::OnMouseScrolledEvent(MouseScrolledEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel += e.GetYOffset();
		io.MouseWheelH += e.GetXOffset();

		return false;
	}

	bool IMGUILayer::OnKeyPressedEvent(KeyPressedEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[LINA_KEY_LCTRL] || io.KeysDown[LINA_KEY_RCTRL];
		io.KeyShift = io.KeysDown[LINA_KEY_LSHIFT] || io.KeysDown[LINA_KEY_RSHIFT];
		io.KeyAlt = io.KeysDown[LINA_KEY_LALT] || io.KeysDown[LINA_KEY_RALT];
		io.KeySuper = io.KeysDown[LINA_KEY_LGUI] || io.KeysDown[LINA_KEY_RGUI];

		return false;
	}

	bool IMGUILayer::OnKeyReleasedEvent(KeyReleasedEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;

		return false;
	}

	bool IMGUILayer::OnKeyTypedEvent(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter((unsigned short)keycode);

		return false;
	}

	bool IMGUILayer::OnWindowResizeEvent(WindowResizeEvent & e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		//glViewport(0, 0, e.GetWidth(), e.GetHeight());

		return false;
	}
}

