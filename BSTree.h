#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <ostream>
#include "BSNode.h"

template <typename T>
class BSTree {

	private:
		    BSNode<T>* root;
		        int nelem;

			/* ================= BÚSQUEDA ================= */

			    BSNode<T>* search(BSNode<T>* n, T e) const {
				            if (n == nullptr) {
						                throw std::runtime_error("Elemento no encontrado");
								        }

					            if (e < n->elem) {
							                return search(n->left, e);
									        }
						            if (e > n->elem) {
								                return search(n->right, e);
										        }

							            return n;
								        }

	public:
			        BSTree() {
					        root = nullptr;
						        nelem = 0;
							    }

				    int size() const {
					            return nelem;
						        }

				        T search(T e) const {
						        return search(root, e)->elem;
							    }

					    T operator[](T e) const {
						            return search(e);
							        }

					    /* ================= INSERCIÓN ================= */

	private:
					        BSNode<T>* insert(BSNode<T>* n, T e) {
							        if (n == nullptr) {
									            return new BSNode<T>(e);
										            }

								        if (e == n->elem) {
										            throw std::runtime_error("Elemento duplicado");
											            }

									        if (e < n->elem) {
											            n->left = insert(n->left, e);
												            } else {
														                n->right = insert(n->right, e);
																        }

										        return n;
											    }

	public:
						    void insert(T e) {
							            root = insert(root, e);
								            nelem++;
									        }

						    /* ================= RECORRIDO ================= */

	private:
						        void print_inorder(std::ostream& out, BSNode<T>* n) const {
								        if (n != nullptr) {
										            print_inorder(out, n->left);
											                out << n->elem << " ";
													            print_inorder(out, n->right);
														            }
									    }

	public:
							    friend std::ostream& operator<<(std::ostream& out, const BSTree<T>& bst) {
								            bst.print_inorder(out, bst.root);
									            return out;
										        }

							    /* ================= ELIMINACIÓN ================= */

	private:
							        T max(BSNode<T>* n) const {
									        if (n->right == nullptr) {
											            return n->elem;
												            }
										        return max(n->right);
											    }

								    BSNode<T>* remove_max(BSNode<T>* n) {
									            if (n->right == nullptr) {
											                return n->left;
													        }
										            n->right = remove_max(n->right);
											            return n;
												        }

								        BSNode<T>* remove(BSNode<T>* n, T e) {
										        if (n == nullptr) {
												            throw std::runtime_error("Elemento no encontrado");
													            }

											        if (e < n->elem) {
													            n->left = remove(n->left, e);
														            }
												        else if (e > n->elem) {
														            n->right = remove(n->right, e);
															            }
													        else {
															            if (n->left != nullptr && n->right != nullptr) {
																	                    n->elem = max(n->left);
																			                    n->left = remove_max(n->left);
																					                } else {
																								                if (n->left != nullptr) {
																											                    n = n->left;
																													                    } else {
																																                        n = n->right;
																																			                }
																										            }
																            }

														        return n;
															    }

	public:
									    void remove(T e) {
										            root = remove(root, e);
											            nelem--;
												        }

									    /* ================= DESTRUCTOR ================= */

	private:
									        void delete_cascade(BSNode<T>* n) {
											        if (n != nullptr) {
													            delete_cascade(n->left);
														                delete_cascade(n->right);
																            delete n;
																	            }
												    }

	public:
										    ~BSTree() {
											            delete_cascade(root);
												        }
};

#endif

