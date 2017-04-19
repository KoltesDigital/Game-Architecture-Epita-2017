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
				assert(_instance != nullptr); // Instance should be assigned.
				return *_instance;
			}

			static T *assign(T* newInstance = nullptr)
			{
				auto previousInstance = _instance;
				_instance = newInstance;
				return previousInstance;
			}

		private:
			static T *_instance;
		};

		template <typename T>
		T *Provider<T>::_instance = nullptr;
	}
}
