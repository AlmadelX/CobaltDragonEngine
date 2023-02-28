#pragma once

#include <vector>

#include "Layer.h"

namespace CDE {

	class LayerStack
	{
		using Layers = std::vector<Layer*>;

	public:
		LayerStack() = default;
		LayerStack(const LayerStack& other) = delete;
		LayerStack& operator=(const LayerStack& other) = delete;

		~LayerStack();

		// Takes ownership
		void PushLayer(Layer* layer);
		void PushOverlayer(Layer* overlay);

		// Returns ownership
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		Layers::iterator begin()		  { return m_Layers.begin(); }
		Layers::iterator end()			  { return m_Layers.end(); }
		Layers::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		Layers::reverse_iterator rend()   { return m_Layers.rend(); }

	private:
		Layers m_Layers;
		unsigned int m_InsertIndex = 0;
	};

}
