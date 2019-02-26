#include <stdio.h>

// Funktionsprototypen
unsigned int ggT1(unsigned int m, unsigned int n);				/*klassischer Algorithmus*/
unsigned int ggT1_rekursiv(unsigned int m, unsigned int n);

unsigned int ggT2(unsigned int m, unsigned int n);				/*verbesserter Algorithmus*/
unsigned int ggT2_rekursiv(unsigned int m, unsigned int n);

unsigned int ggT3(unsigned int m, unsigned int n);				/*binär*/
unsigned int ggT3_rekursiv(unsigned int m, unsigned int n);

int main(void) {
	
	// Deklaration der Variablen m und n
	unsigned int m, n;
	
	// Eingabe vcn m und n durch den User
	printf("Gib hier die erste Zahl ein: \n");
	scanf("%u/n", &m);
	
	printf("Gib hier die zweite Zahl ein: \n");
	scanf("%u/n", &n);
	
	// Methodenaufruf und Ergebnisausgabe
	printf("Der ggT von %u und %u ist %u\n", m, n, ggT1(m,n));
	printf("Der ggT (rekursiv) von %u und %u ist %u\n", m, n, ggT1_rekursiv(m,n));
	
	printf("Der verbesserte ggT von %u und %u ist %u\n", m, n, ggT2(m,n));
	printf("Der verbesserte (rekursiv) ggT von %u und %u ist %u\n", m, n, ggT2_rekursiv(m,n));
	
	printf("Der ggT zur Basis 2 von %u und %u ist %u\n", m, n, ggT3(m,n));
	printf("Der ggT zur Basis 2 (rekursiv) von %u und %u ist %u\n", m, n, ggT3_rekursiv(m,n));
	
	return 0;	
}

// Klassischer Euklid-Algorithmus
unsigned int ggT1(unsigned int m, unsigned int n) {
	
	// Überprüfung, ob es sich um die selbe Zahl handelt
	while(m != n) {
		
		// Ausnahme: Ein Paramater ist 0
		if(n == 0 || m == 0) {
			
			return 0;
	
		} else if(m > n) {
			
			m = m - n;
		} else {
			
			n = n - m;
		}
	}
	
	return m;
}	

// Klassischer Algorithmus rekursiv
unsigned int ggT1_rekursiv(unsigned int m, unsigned int n){
	
	// Ausnahme: Ein Paramater ist 0
	if(m == 0 || n == 0){
		
		return 0;
	}
	
	//Abbruchbedingung
	if(m == n) {
		
		return m;
		
	// Fallunterscheidung	
	} else if (m > n){
		
		return ggT1_rekursiv(m-n, n);
		
	} else {
		
		return ggT1_rekursiv(n, n-m);
	}
	
}

// Verbesserter Algorithmus
unsigned int ggT2(unsigned int m, unsigned int n) {
	
	// Variabel für den Tausch von m und n
	unsigned int temp;
	
	// Ausnahme: Ein Paramater ist 0
	if(m == 0 || n == 0){
		
		return 0;
	}	
	
	while(n != 0) {
		
		temp = m;
		m = n;
		n = temp%n;
	}
	
	return m;
}	

// Verbesserter Algorithmus rekursiv
unsigned int ggT2_rekursiv(unsigned int m, unsigned int n){
	
	// Abbruchbedingung
	if(n == 0) {
		
		return m;
		
	// Algorithmus
	} else {
		
		return ggT2_rekursiv(n, m%n);
	}
}


// Algorithmus für Basis 2
unsigned int ggT3(unsigned int m, unsigned int n){
	
	while(m != n) {
		
		if(m%2 != 0) {
			
			// m ungerade und n ungerade
			if(n%2 != 0) {
				
				if(m > n) {
			
					m = m - n;
					
				} else {
			
					n = n - m;
				}
				
			// m ungerade und n gerade	
			} else {
				
				n = n / 2;
			}
			
		} else {
			
			// m gerade und n ungerade
			if(n%2 != 0) {
				
				m = m / 2;
				
			// m gerade und n gerade	
			} else {
				
				if(m > n) {
			
					m = m - n;
					
				} else {
			
					n = n - m;
				}
			}
		}
	}
	
	return m;
}

// Algorithmus für Basis 2 rekursiv
unsigned int ggT3_rekursiv(unsigned int m, unsigned int n) {
	
	// Abbruchbedingung
	if (m == n || m == 0 || n == 0) {
		
		return m;
		
	} else if (m == 1 || n == 1) {
		
		return 1;
	}
		
	 else if(m%2 != 0) {
		
		// m ist ungerade und n ist ungerade
		if(n%2 != 0) {
			
			if(m > n) {
				
				return ggT3_rekursiv(m-n, n);
				
			} else {
				
				return ggT3_rekursiv(n, n-m);
			}
		// m ist ungerade und n ist gerade	
		} else {
			
			return ggT3_rekursiv(m, n/2);
		}
	} else {
		
		// m ist gerade und n ist ungerade
		if(n%2 != 0) {
			
			return ggT3_rekursiv(m/2, n);
			
		// m ist gerade und n ist gerade	
		} else {
			
			return 2 * ggT3_rekursiv(m/2, n/2);
		}
	}
}