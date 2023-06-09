#include <iostream>
#include <string>

using namespace std;
class Interpreter_roman_nambers;
class Thousand;
class Hundred;
class Ten;
class Unity;

class Interpreter_roman_nambers{

public:
	Interpreter_roman_nambers();
	explicit Interpreter_roman_nambers(int){}
	virtual ~Interpreter_roman_nambers(){}
	virtual void interprer(string&,int&);
	int interprer(string);

protected:
	virtual char one(){return 0;}
	virtual string four(){return nullptr;}
	virtual char five(){return 0;}
	virtual string nine(){return nullptr;}
	virtual int multipliter(){return 0;}	

private:
	Interpreter_roman_nambers *thousand;
	Interpreter_roman_nambers *hundred;
	Interpreter_roman_nambers *ten;
	Interpreter_roman_nambers *unity;

};

class Thousand :public Interpreter_roman_nambers{

public:
	explicit Thousand(int) : Interpreter_roman_nambers(1){};

protected:
	 char one() override {return 'M';}
	 string four() override {return "";}//brak M jest najwienksze
	 char five() override {return '\0';}//sprawdzenie czy koniec lini 
	 string nine() override {return "";}
	 int multipliter() override {return 1000;}
	
};

class Hundred :public Interpreter_roman_nambers{

public:
	explicit Hundred(int) : Interpreter_roman_nambers(1){};

protected:
	 char one() override {return 'C';}
	 string four() override {return "CD";}
	 char five() override {return 'D';} 
	 string nine() override {return "CM";}
	 int multipliter() override {return 100;}
};

class Ten :public Interpreter_roman_nambers{

public:
	explicit Ten(int) : Interpreter_roman_nambers(1){};

protected:
	 char one() override {return 'X';}
	 string four() override {return "XL";}
	 char five() override {return 'L';} 
	 string nine() override {return "XC";}
	 int multipliter() override {return 10;}
};

class Unity :public Interpreter_roman_nambers{

public:
	explicit Unity(int) : Interpreter_roman_nambers(1){};

protected:
	 char one() override {return 'I';}
	 string four() override {return "IV";}
	 char five() override {return 'V';} 
	 string nine() override {return "IX";}
	 int multipliter() override {return 1;}
};

//////////////////////////////////////////////////////////////////////////////////////////

Interpreter_roman_nambers::Interpreter_roman_nambers(){
	//inicjuje fukcje pokolei
	hundred=new Hundred(1);
	thousand=new Thousand(1);
	ten=new Ten(1);
	unity=new Unity(1);}



int Interpreter_roman_nambers::interprer(string number){
	int total=0;

	if(number.empty()){return 0;}//sprawdz czy ktoś coś podał
	
	thousand->interprer(number,total);
	hundred->interprer(number,total);
	ten->interprer(number,total);
	unity->interprer(number,total);
	
	return total;}



void Interpreter_roman_nambers::interprer(string &entry,int &result){
	int index=0;
	string test=entry.substr(0,2);
		
	//sprawdznie najwarzniejszych liczb rzymskich
	if(test==nine()){
		result+=9*multipliter();
		index+=2;}
	else if(test==four()){
		result+=4*multipliter();
		index+=2;}
	else{
		if(entry[0]==five()){
			result+=5;
			index=1;}
		else{index=0;}}

	//sprawdzaanie jensci ostatnich 3 cyfr,jesli przetem byLa specjalna 5 lub 4
	for (int i=index+3;index<i;index++){
		if(entry[index]==one()){result+=1*multipliter();}
		else{break;}}

	//wycinanie przerobionej liczby-paru liczb z zakresu 
	int length=entry.length()-index;
	entry=entry.substr(index,length);}




int main(int argc, char const *argv[]){
	
	Interpreter_roman_nambers interp;
	string number="MMCXLVI";
	cout<<"liczba rzymska  "<<number<<" to liczba dziesietna "<<interp.interprer(number);

	return 0;
}
