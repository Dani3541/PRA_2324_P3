#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include "BSTree.h"
#include "TableEntry.h"
#include "Dict.h"
#include <ostream>
#include <string>
#include <stdexcept>

template <typename V>
class BSTreeDict : public Dict<V> {
	private:
		    BSTree<TableEntry<V>>* tree;

	public:
		        BSTreeDict() : tree(new BSTree<TableEntry<V>>()) {}

			    ~BSTreeDict() { delete tree; }

			        friend std::ostream& operator<<(std::ostream& out, const BSTreeDict<V>& bstd) {
					        out << *(bstd.tree);
						        return out;
							    }

				    V operator[](const std::string& key) {
					            return tree->search(TableEntry<V>(key)).value;
						        }

				        void insert(const std::string& key, V value) override {
						        TableEntry<V> entry(key, value);
							        tree->insert(entry);
								    }

					    V search(const std::string& key) override {
						            return tree->search(TableEntry<V>(key)).value;
							        }

					        V remove(const std::string& key) override {
							        TableEntry<V> entry(key);
								        V value = tree->search(entry).value;
									        tree->remove(entry);
										        return value;
											    }

						    int entries() override {
							            return tree->size();
								        }
};

#endif

