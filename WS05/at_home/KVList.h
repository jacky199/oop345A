/**********************************************************
 * Name: jack
 * Student ID: 123456789
 * Seneca email:jack@myseneca.ca
 **********************************************************/
#ifndef SICT_KVList_h
#define SICT_KVList_h
#include<iostream>
namespace sict{
	template<typename T>
	class KVList{
		T* list;
		int num;
	public:
		KVList(){
			list = nullptr;
			num = 0;
		}

		KVList(int n){
			if (n > 0){
				list = new T[n];
				num = n;
			}
			else{
				throw n;
			}
		}

		KVList(KVList&& s){
			if (s.list != nullptr){
				list = s.list;
				num = s.num;
				s.list = nullptr;
				s.num = 0;
			}
			else{
				list = nullptr;
				num = 0;
			}
		}

		~KVList(){
			delete[] list;
			list = nullptr;
		}

		const T& operator[](size_t i) const{
			if (i < 0 || i >= num) {
				throw "Outside bounds";
			}
			return list[i];
		}

		template<typename F>void display(std::ostream& os, F f) const{
			if (num != 0){
				for (int i = 0; i < num; i++){
					list[i].display(os, f);
				}
			}
		}

		void push_back(const T& t){
			static int n = 0;
			if (n < num) {
				list[n] = t;
				n++;
			}
		}

		KVList(const KVList& s)= delete;
		KVList& operator=(const KVList& s)=delete;
		KVList& operator=(KVList&& s)=delete;
	};
}
#endif