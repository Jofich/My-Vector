// my Vector class 
namespace shp 
{
    class vector 
	{
	private:
		int all{};
		int m_size{};
		int* data = new int[all];
	public:

		int operator[](int ind) {
			if(ind < m_size && ind >=0)	return data[ind];
		}

		vector(int size_array) {
			m_size = size_array;
			all = size_array * 2;
			data = new int[all];
			fill(data, all);
		}
		void fill(int* array, int array_size, int fill_symbol=0) {
			for (int i = 0; i < array_size; i++) {
				array[i] = fill_symbol;
			}
		}
		int size() {
			return this->m_size;
		}
		void push_back(int number) {
			if (m_size + 1 > all) {
				resize();
			}
			data[m_size] = number;
			m_size++;
		}

		void resize() {
			int new_size = all * 2;
			int* resized_data = new int[new_size];
			fill(resized_data, new_size);
			for (int i = 0; i < all; i++) {
				resized_data[i] = data[i];
			}
			delete[] data;
			data = nullptr;
			all = new_size;
			data = new int[new_size];
			fill(data, new_size);
			for (int i = 0; i < new_size; i++) {
				data[i] = resized_data[i];
			}
			delete[] resized_data;
		}
	};

}
