/**********************************************************
 * Name: Jack ZHAO
 * Student ID: 123456789
 * Seneca email:Jack ZHAO@myseneca.ca
 **********************************************************/
#ifndef LVPair_SICT_H
#define LVPair_SICT_H

#include <iostream>
namespace sict {
	template<typename L, typename V>
	class LVPair {
		L label;
		V value;
	public:
		LVPair() : label(), value() {}
		LVPair(const L& Label, const V& Value) {
			label = Label;
			value = Value;
		}
		virtual void display(std::ostream& os) const {
			os << label << " : " << value << std::endl;
		}
		const L& getLabel() const{
            return label;
        }
        const V& getValue() const { 
		return  value; 
		}
    };

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& p) {
		p.display(os);
		return os;
	}

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V valu;
		static size_t width;

	public:
		SummableLVPair() {}
		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v){
			if (width < label.size()){
				width = label.size();
			}
		}
	const static V& getInitialValue() {
			return valu;
		}
	
		V sum(const L& label, const V& sum) const{
			return (label == LVPair<L, V>::getLabel()) ? LVPair<L, V>::getValue() + sum : sum;
		}

		void display(std::ostream& os) const{
			os.setf(std::ios::left);
			os.width(width);
			LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
		}
	};

	template<typename L, typename V>
	size_t SummableLVPair<L, V>::width = 0u;

	template<>
	int SummableLVPair<std::string, int>::valu = 0;

	template<>
	std::string SummableLVPair<std::string, std::string>::valu = "\0";

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& sum1, const std::string& sum2) const{
		return (sum1 == LVPair<std::string, std::string>::getLabel()) ? (sum2 + " " + LVPair<std::string, std::string>::getValue()) : sum2;
	}
}


#endif 