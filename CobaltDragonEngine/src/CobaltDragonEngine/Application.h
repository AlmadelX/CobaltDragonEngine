#pragma once

namespace CDE {

	class Application
	{
	public:
		inline static Application& Get() { return *s_Instance; }

		Application();
		virtual ~Application();

		void Run();

	private:
		static Application* s_Instance;
	};

	// To be defined by client
	Application* CreateApplication();

}
