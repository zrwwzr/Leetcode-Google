template <class X> class copied_ptr
{
public:
	explicit copied_ptr(X* p = 0) throw()       : itsPtr(p) {}
	~copied_ptr()                               {itsPtr;}
	copied_ptr(const copied_ptr& r)             {copy(r);}
	copied_ptr& operator=(const copied_ptr& r)
	{
		if (this != &r) {
			delete itsPtr;
			itsPtr = NULL;
			deep_copy(r);
		}
		return *this;
	}

	X& operator*()  const throw()               {return *itsPtr;}
	X* operator->() const throw()               {return itsPtr;}

private:
	X* itsPtr;
	void deep_copy(const copied_ptr& r)  {
		itsPtr = r.itsPtr ? new X(*r.itsPtr) : 0;
	}
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
	copied_ptr<Complex> p(new Complex(1.0, 2.0));
	copied_ptr<Complex> q(new Complex(1.0, 3.0));
	(*q).print();	
	q = p;
	(*q).print();
	return 0;
}
