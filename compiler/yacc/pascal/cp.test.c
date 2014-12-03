int myfunction(int varInt, char varChar, float varFloat, double varDouble){
	int iA = 0;
	double dA = varDouble;
	char chA, chB, chC;

	if(iA)
		iA = 1;
	
	if(0){
		chA = chB;
		chA = 0;
	}else{
		chC = chA;
		chC = 1;
	}

	chC = chA;
	
	switch(varInt){
		case 0:
			break;
		default:
			return (1);
	}

	for(iA;iB;iC){
		continue;
	}

	while(1){
		if(0){
			break;
		}
		continue;
	}

	return (1);
}

char doublefunc(void){
	if( (a+b) <= (c*d+0)){
		a = b;
	}
	
	a-=0;
	a+=a;
	a/=b;
	a*=c;
	a%=d;

	return (2);
}

int main(void){
	return (0);
}
