#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
	public:
		    std::string key;
		        V value;

			    TableEntry(const std::string& k, V v = V()) : key(k), value(v) {}

			        bool operator<(const TableEntry<V>& other) const {
					        return key < other.key;
						    }

				    bool operator>(const TableEntry<V>& other) const {
					            return key > other.key;
						        }

				        bool operator==(const TableEntry<V>& other) const {
						        return key == other.key;
							    }

					    friend std::ostream& operator<<(std::ostream& out, const TableEntry<V>& e) {
						            out << e.key << " --> " << e.value;
							            return out;
								        }
};

#endif

