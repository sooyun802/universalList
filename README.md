## Universal List

* List of elements enabled to have various data types
* Doubly linked list
* Only sequentially accessible

## Functions

* `constructor ();` creates an empty list
* `constructor (const value_type* arr);` creates a list with elements in arr
* `destructor (void);` destroys the list without memory leak
* `operator +` concatenates the two given lists *a* and *b* (e.g., *a*+*b*)
* `operator ==` finds whether *a* and *b* have the same elements or not (e.g., *a*==*b*)
* `void set (int n, const value_type& T);`
	* updates the element of index *n* with value *T*
	* any other elements should not be modified
	```
	Object obj = ...;  
	list.set (obj);
	```
* `value_type get (int n);`
	* returns the element of index *n*
	* any other elements should not be modified
	```
	Objet obj = list.get ();
	```
* `value_type insert (int n, const value_type& T);`
	* inserts value *T* in the list at index *n*
	* increases the list size by one
	* returns the value of the element
	```
	Object obj = ...;  
	Object inserted_obj;  
	inserted_obj = list.insert (3, obj);
	```
* `value_type erase (int n);`
	* removes the element in the list at index *n*
	* decreases the list size by one
	* returns the value of the element
	```
	Object obj = list.erase (2);
	```
* `int size (void);`
	* returns the byte size of the given list
	```
	int len = list.size ();
	```
* `void pop_back (void);`
	* removes the last element of the list
	* decreases the list length
	```
	list.pop_back ();
	```
* `void pop_front (void);`
	* removes the first element in the list
	* decreases the list length
	```
	list.pop_front ();
	```
* `void push_back (const value_type& T);`
	* inserts value *T* to the last element in the list
	* increases the list size by one
	```
	Object obj = ...;  
	list.push_back (obj);
	```
* `void push_front (const value_type& T);`
	* inserts value *T* to the first element in the list
	* increases the list size by one
	```
	Object obj = ...;  
	list.push_front (obj);
	```

## Execution

* `make` build executable
* `make header` build static library with the name of *unvlist.a*
* `make clean` remove generated files
