template <class X> class counted_ptr
{
private:
	//wrap the real pointer object and counter
	struct counter{
		X *ref;
		unsigned ref_counter;
		counter(X* p = NULL, unsigned c = 1) : ref(p), ref_counter(c){}
	};
	counter *cptr;
	void release(){
		//currently it is pointing to some other object
		if(cptr){
			//decrease the pointer counter by 1
			//if after decreasing, its counter becomes 0, delete it
			if(--cptr->ref_counter == 0){
				delete cptr->ref;
				cptr->ref = NULL;

			}
		}
	}
	void acquire(counter *c){
		cptr = c;
		if(c) ++c->ref_counter;
	}

public:
	//explicit constructor
	explicit counted_ptr(X *p = NULL) : cptr(NULL){
		if(p) cptr = new counter(p);
	}
	//destructor
	~counted_ptr(){ release(); }
	//create a new smart pointer via constructor
	counted_ptr(const counted_ptr &rhs){
		acquire(rhs.cptr);
	};
	//assignment
	counted_ptr& operator=(const counted_ptr &rhs){
		if(this != &rhs){
			//first release any object it points to
			release();
			//second set to the rhs and increase the ref_counter
			acquire(rhs.cptr);
		}
		return *this;
	}
	//other operators overloading
	X& operator*() const throw()	{ return *cptr->ref; }
	X* operator->() const throw()	{ return cptr->ref; }
	X* get() const throw()			{ return cptr ? cptr->ref : NULL; }
};
class Complex{
private:
	double real;
	double img;
public:
	explicit Complex(double r = 0.0, double i = 0.0) : real(r), img(i){}
	void print(){
		cout<<real<<"+"<<img<<"i"<<endl;
	}
};

int main(void)
{	
	counted_ptr<Complex> p(new Complex(1.0, 2.0));
	counted_ptr<Complex> q(new Complex(1.0, 3.0));
	counted_ptr<Complex> m(q);
	q = p;
	return 0;
}
