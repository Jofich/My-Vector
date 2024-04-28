// my Vector class 
#include < cassert>
namespace shp
{
	template <typename T>
	class vector
	{
	private:
		int m_capacity{};
		int m_size{};
		T* data = nullptr;// new T[m_capacity];
	public:
		vector(int size_array, T fill_symbol =0) {
			m_size = size_array;
			m_capacity = size_array * 2;
			data = new T[m_capacity];
			fill(data, m_size,fill_symbol);
		}
		//TODO конструктор копирования 
		vector& operator=(const vector&& copy) {
			delete data;
			data = copy.data;
			m_size = copy.m_size;
			m_capacity = m_size;
		}
		T operator[](int ind) {
			assert(("ind must be in range [0; size-1]",ind < m_size&& ind >= 0));
			return data[ind];

		}
		int capacity() {
			return m_capacity;
		}
		void fill(T* array, int array_size, T fill_symbol = 0) {
			for (int i = 0; i < array_size; i++) {
				array[i] = fill_symbol;
			}
		}
		int size() {
			return this->m_size;
		}
		void push_back(T number) {
			if (m_size + 1 > m_capacity) {
				resize();
			}
			data[m_size-1] = number;
			m_size++;
		}
		T back() {
			return data[m_size-1];
		}
		void pop_back() {
			
			data[m_size-1] = 0;
			m_size -= 1;
		}
		T* begin() {
			return data;
		}
		T* end() {
			return data + m_size;
		}
		void resize() {
			int new_size = m_capacity * 2;
			T* resized_data = new T[new_size];
			fill(resized_data, new_size);
			for (int i = 0; i < m_capacity; i++) {
				resized_data[i] = data[i];
			}
			delete[] data;
			data = nullptr;
			m_capacity = new_size;
			data = new T[new_size];
			fill(data, new_size);
			for (int i = 0; i < new_size; i++) {
				data[i] = resized_data[i];
			}
			delete[] resized_data;
		}
	};

}
