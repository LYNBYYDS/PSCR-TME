namespace pr {
8
9 template <typename T>
10 class Vector {
11 size_t alloc_sz;
12 T * tab;
13 size_t sz;
14
15 void ensure_capacity(size_t n) {
16 // cf TD2
17 }
18
19 public:
20 Vector(int size=10): alloc_sz(size),sz(0) {
21 tab = new T [alloc_sz];
22 }
23 virtual ~Vector() {
24 delete [] tab;
25 }
26
27 const T & operator[] (size_t index) const {
28 return tab[index];
29 }
30 T& operator[] (size_t index) {
31 return tab[index];
32 }
33
34 void push_back (const T& val) {
35 ensure_capacity(sz+1);
36 tab[sz++]=val;
37 }
38
39 size_t size() const { return sz ; }
40
41 // Declarations et implantations non-const
42 typedef T* iterator;
43 iterator begin() {
44 return tab;
45 }
46 iterator end() {
47 return tab + sz;
48 }
49
50 // Declarations et implantations const
51 typedef const T* const_iterator;
52 const_iterator begin() const {
53 return tab;
54 }
55 const_iterator end() const {
56 return tab+sz;
57 }
58 };
59
60 } /* namespace pr */
61
62 #endif /* SRC_VECTOR_H_ */