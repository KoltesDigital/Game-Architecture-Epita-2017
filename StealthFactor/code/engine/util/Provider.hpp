#pragma once

#include <cassert>

namespace engine
{
	namespace util
	{
		template <typename T>
		class Provider
		{
		public:
			static T &getInstance()
			{
				assert(instance != nullptr); // Instance should be assigned.
				return *instance;
			}

			static T *assign(T* newInstance = nullptr)
			{
				auto previousInstance = instance;
				instance = newInstance;
				return previousInstance;
			}

		private:
			static T *instance;
		};

		template <typename T>
		T *Provider<T>::instance = nullptr;
	}
}
