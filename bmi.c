#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


	// Sturct to hold state information
typedef struct {
	const char* code;
	const char* name;
} StateData;

	// Struct to hold month information
typedef struct {
	const char* code;
	const char* name;
} MonthData;


// Function store State Data
	const char* getState(char code[]) {
	// Array of StateData
	    StateData stateData[] = {
	        {"01", "Johor"}, {"21", "Johor"}, {"22", "Johor"}, {"23", "Johor"}, {"24", "Johor"},
	        {"02", "Kedah"}, {"25", "Kedah"}, {"26", "Kedah"}, {"27", "Kedah"},
	        {"03", "Kelantan"}, {"28", "Kelantan"}, {"29", "Kelantan"},
	        {"04", "Melaka"}, {"30", "Melaka"},
	        {"05", "Negeri Sembilan"}, {"31", "Negeri Sembilan"}, {"59", "Negeri Sembilan"},
	        {"06", "Pahang"}, {"32", "Pahang"}, {"33", "Pahang"},
	        {"07", "Pulau Pinang"}, {"34", "Pulau Pinang"}, {"35", "Pulau Pinang"},
	        {"08", "Perak"}, {"36", "Perak"}, {"37", "Perak"}, {"38", "Perak"}, {"39", "Perak"},
	        {"09", "Perlis"}, {"40", "Perlis"},
	        {"10", "Selangor"}, {"41", "Selangor"}, {"42", "Selangor"}, {"43", "Selangor"}, {"44", "Selangor"},
	        {"11", "Terengganu"}, {"45", "Terengganu"}, {"46", "Terengganu"},
	        {"12", "Sabah"}, {"47", "Sabah"}, {"48", "Sabah"}, {"49", "Sabah"},
	        {"13", "Sarawak"}, {"50", "Sarawak"}, {"51", "Sarawak"}, {"52", "Sarawak"}, {"53", "Sarawak"},
	        {"14", "Wilayah Persekutuan (Kuala Lumpur)"}, {"54", "Wilayah Persekutuan (Kuala Lumpur)"},
	        {"55", "Wilayah Persekutuan (Kuala Lumpur)"}, {"56", "Wilayah Persekutuan (Kuala Lumpur)"}, {"57","Wilayah Persekutuan (Kuala Lumpur)"},
	        {"15", "Wilayah Persekutuan (Labuan)"}, {"58", "Wilayah Persekutuan (Labuan)"},
	        {"16", "Wilayah Persekutuan (Putrajaya)"},
	        {"82", "Negeri Tidak Diketahui"}
		};
    
	    // For Loop in array to find the matching state code
	for (int i = 0; i < sizeof(stateData) / sizeof(stateData[0]); i++) {
    		if (strcmp(stateData[i].code, code) == 0) {
    			return  stateData[i].name;
    		}
    	}
		// If state code is not found, prompt "wrong input"
	return "Invalid IC Number";
}

// Function store Month Data
	const char* getMonth(char code[]) {
    	// Array of Month
    		MonthData monthData[] = {
        	{"01", "January"}, {"02", "February"}, {"03", "March"}, {"04", "April"}, {"05", "May"}, {"06", "June"},
        	{"07", "July"}, {"08", "August"}, {"09", "September"}, {"10", "October"}, {"11", "November"}, {"12", "December"}
    		};

    	// For Loop in array to find the matching month code
    		for (int i = 0; i < sizeof(monthData) / sizeof(monthData[0]); i++) {
        		if (strcmp(monthData[i].code, code) == 0) {
            			return monthData[i].name;
        		}
    		}
    	// If month code is not found, prompt "wrong input"
    		return "Invalid IC Number";
}

// Function to calculate current age
	void calculateAge(int birthYear, int birthMonth, int birthDay, int *ageYears, int *ageMonths, int *ageDays) {
	
	time_t now;
	struct tm *currentTime;
	time(&now);
	currentTime = localtime(&now);
	
	int currentYear = currentTime -> tm_year + 1900; // Current Year
	int currentMonth = currentTime -> tm_mon + 1; // Current Month
	int currentDay = currentTime -> tm_mday; // Current Day


	*ageYears = currentYear - birthYear;
	*ageMonths = currentMonth - birthMonth;
	*ageDays = currentDay - birthDay;
	
	if (*ageMonths < 0) {
		(*ageYears) --;
		*ageMonths += 12;
	} 
	if (*ageDays < 0) {
		if (*ageMonths == 0) {
			(*ageYears) --;
			*ageMonths = 11;
		} else {
			(*ageMonths) --;
		}
		*ageDays += 30; //  Month has 30 days
	}
}


int main() {
   	char name[30], noIC[13];
    	double height, weight;
    	double bmi;

    // Input Name: User Enter Name
	printf("Enter your Name: ");
	scanf("%s", name);

	// Input IC: User Enter noIC Number
	printf("Enter your IC Number (without dash): ");
	scanf("%s", noIC);
	
	// Extracting information for state from IC Number
	char stateCode[3];
	strncpy(stateCode, noIC + 6, 2);
	stateCode[2] = '\0';
	
	// Extract year, month, and day from IC number
    	char year[3], month[3], day[3];
    	memcpy(year, noIC, 2);
   	year[2] = '\0';
    	memcpy(month, noIC + 2, 2);
    	month[2] = '\0';
    	memcpy(day, noIC + 4, 2);
    	day[2] = '\0';
    	
    	// Extract Gender
    	char gender[8];
    	int lastDigit = noIC[11] - '0'; 
    	
    	if (lastDigit % 2 == 0) {
    	strcpy(gender,"Female"); 
    	} else {
    	strcpy(gender,"Male") ; 
    	}
    	
    	// Convert year to full year (20YY) or (19YY)
     	char fullYear[5];
   	if (year[0] >= '0' && year[0] <= '2') { // Assuming years 00-29 belong to 2000-2029
        	strcpy(fullYear, "20");
    	} else {
        	strcpy(fullYear, "19");
    	} 
    	strcat(fullYear, year);
    	
    	
    	// Calculate current age
    	int birthYear = atoi(fullYear);
    	int birthMonth = atoi(month);
    	int birthDay = atoi(day);
    	int ageYears, ageMonths, ageDays;
    	
    	calculateAge(birthYear, birthMonth, birthDay, &ageYears, &ageMonths, &ageDays);
    
    	
	// Convert month code to month name
	const char* monthName = getMonth(month);
	

    // Input Height: User Enter Height (unit meter)
	printf("Enter your Height(mtr): ");
	scanf("%lf", &height);

    // Input Weight: User Enter Weight (unit kg)
	printf("Enter your Weight(kg): ");
	scanf("%lf", &weight);

    // Calculation for BMI
	bmi = weight / (height * height);



    // Calculation for Ideal Weight and Improve Weight
    double idealWeight, weightDetail;
	
	idealWeight = 23.0 * height * height;
	weightDetail = weight - idealWeight;


	// Personal Detail OUTPUT
    printf("\n\t== Personal Detail==\n");

	printf("Name: %s\n", name);
	printf("IC Number: %s\n", noIC);
	printf("You were born in: %s\n", getState(stateCode));
    printf("Date of Birth: %s %s %s\n", day, monthName, fullYear);
    printf("Age : %d Years, %d Months, %d Days\n", ageYears, ageMonths, ageDays);
    printf("You are: %s\n", gender);

	
	// BMI Detail
	printf("\n\t== BMI Detail ==\n");
	printf("BMI: %5.2lf\n", bmi);

	// Using if - else statement for BMI status
    	if (bmi <= 18.5) {
        	printf("Status: Underweight\n");
   	} else if (bmi <= 22.90) {
        	printf("Status: Normal weight\n");
    	} else if (bmi <= 23.90) {
       		printf("Status: Ideal Weight\n");
    	} else if (bmi <= 25.0) {
        	printf("Status: Normal Weight\n");
    	} else if (bmi <= 30.0) {
        	printf("Status: Overweight\n");
    	} else {
       		printf("Status: Obesity\n");
    	} 
    	
    	// Detail of IdealWeight and WeightDetail to Lose or Gain
    	printf("Your Ideal Weight: %5.2lfkg\n", idealWeight);
    	printf("Weight to Lose/Gain: %5.2lfkg to achieve Ideal Weight\n", weightDetail);


    return 0;
}
