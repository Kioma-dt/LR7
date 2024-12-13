#include <iostream>
#include <string>
#include <cmath>

int main();

std::string MirrorNumber(std::string number) {
    for (int i = 0; i < number.size() / 2; i++) {
        std::swap(number[i], number[number.size() - i - 1]);
    }

    return number;
}

std::string AddZeroes(std::string number, size_t size){
    number = MirrorNumber(number);
    while (number.size() != size){
        number.push_back('0');
    }

    return MirrorNumber(number);
}

std::string DeleteZeroes(std::string number){
    while (number[0] == '0'){
        number.erase(0, 1);
    }

    if (number.empty()){
        number.push_back('0');
    }

    return number;
}

std::string AddMinus(std::string number){
    if (number[0] == '-'){
        number.erase(0, 1);
        return number;
    }

    return '-' + number;
}

bool Greater(std::string number_1, std::string number_2){
    if (number_1.size() > number_2.size()){
        return true;
    }
    else if (number_1.size() < number_2.size()){
        return false;
    }
    else{
        for (int i = 0; i < number_1.size(); i++){
            if (number_1[i] > number_2[i]){
                return true;
            }
            else if (number_1[i] < number_2[i]){
                return false;
            }
        }
    }

    return false;
}

int CharToInt(char c){
    if (c >= 'A'){
        return (int)c - 'A' + 10;
    }
    return (int)c - '0';
}
char IntToChar(int d){
    if (d >= 10){
        return (char)d - 10 + 'A';
    }
    return (char)d + '0';
}

std::string SumNumbers(std::string number_1, std::string number_2, int system){
    std::string sum;
    int carry = 0, size = std::max(number_1.size(), number_2.size()), temp_sum = 0;
    number_1 = AddZeroes(number_1, size);
    number_2 = AddZeroes(number_2, size);

    for (int i = size - 1; i >= 0;i--){
        temp_sum = CharToInt(number_1[i]) + CharToInt(number_2[i]) + carry;
        carry = 0;
        if (temp_sum >= system) {
            temp_sum -= system;
            carry++;
        }
        sum.push_back(IntToChar(temp_sum));
        temp_sum = 0;
    }

    if (carry > 0){
        sum.push_back('1');
    }

    return MirrorNumber(sum);
}

std::string SubstractNumber(std::string number_1, std::string number_2, int system) {
    bool negative = false;
    if (Greater(number_2,number_1)){
        negative = true;
        std::swap(number_1, number_2);
    }

    std::string difference;
    int carry = 0, size = number_1.size(), temp_difference = 0;
    number_1 = AddZeroes(number_1, size);
    number_2 = AddZeroes(number_2, size);

    for (int i = size - 1; i >= 0; i--){
        temp_difference = CharToInt(number_1[i]) - CharToInt(number_2[i]) - carry;
        carry = 0;
        if (temp_difference < 0){
            carry++;
            temp_difference += system;
        }
        difference.push_back(IntToChar(temp_difference));
        temp_difference = 0;
    }

    if (negative){
        difference.push_back('-');
    }

    return DeleteZeroes(MirrorNumber(difference));
}

std::string DivideByTwo(std::string number){
    std::string quotient;
    int residue = 0, size = number.size(), temp_quotient = 0;

    for (int i = 0; i < size;i++){
        temp_quotient = number[i] - 48 + residue * 10;
        residue = 0;
        if (temp_quotient % 2 == 0){
            temp_quotient /= 2;
        }
        else {
            residue++;
            temp_quotient--;
            temp_quotient /= 2;
        }
        quotient.push_back((char)temp_quotient + 48);
        temp_quotient = 0;
    }

    return DeleteZeroes(quotient);
}

std::string DirectToReverse(std::string number) {
    if (number[0] == '1'){
        for (int i = 1; i < number.size(); i++) {
            number[i] = number[i] == '0' ? '1' : '0';
        }
    }

    return number;
}

std::string DirectToAdditional(std::string number){
    if (number[0] == '1'){
        for (int i = 1; i < number.size(); i++) {
            number[i] = number[i] == '0' ? '1' : '0';
        }
        number = SumNumbers(number, "1", 2);
    }

    return number;
}

std::string DecToDirect(std::string number, bool negative){
    std::string direct;
    while (number != "0"){
        if (number[number.size() - 1] % 2 == 0){
            direct.push_back('0');
            number = DivideByTwo(number);
        }
        else {
           direct.push_back('1');
           number = SubstractNumber(number, "1", 10);
           number = DivideByTwo(number);
        }
    }

    direct.push_back('0');
    if (negative){
        direct.push_back('1');
    }
    else{
       direct.push_back('0'); 
    }

    return MirrorNumber(direct);
}

long long Multiplying(long long number_1, long long number_2){
    long long pow = 0;
    long long result = 0;
    while ((1 << (pow + 1)) < number_2){
        pow++;
    }
    
    result += (number_1 << pow);
    for (int i = (1 << pow) ; i < number_2; i++){
        result += number_1;
    }

    return result;
}

bool checkDivisible(long long number, int divider, int system, int findResidue, int coefficient){
    long long prev_number;
    long long residue;
    do{
        prev_number = number;
        number = number >> system;
        residue = prev_number & findResidue;
        number += Multiplying(residue, coefficient);
    } while (prev_number != number && number > divider);

    int check = divider;
    while (check < number){
        check += divider;
    }

    if (check == number){
        return true;
    }
    return false;
}

void OutputBarrels(int slave, int day){
    int shift = 243 / pow(3, slave);
    for (int i = shift * day; i <= 240; i += shift * 3){
        for (int j = i; j < i + shift && j <= 240; j++){
            std::cout << j << ' ';
        }
    }
    std::cout << '\n';
}

char EnterSlavesDay(int slave){
    char day;
    std::cout << slave << " раб в первый день пьёт из бочек с номерами:\n";
    OutputBarrels(slave, 1);
    std::cout << slave << " раб во второй день пьёт из бочек с номерами:\n";
    OutputBarrels(slave, 2);
    std::cout << "Введите день, когда умрет " << slave << " раб(0 - никогда, 1 - первый день, 2 - второй день)\n";
    while (1){
        std::cin >> day;
        if (day == '0' || day == '1' || day == '2'){
            break;
        }
        std::cout << "Неверный день!\n";
    }

    return day;
}

int FindBarrel(std::string barrel){
    int poison = 0;
    for (int i = 0; i < 5; i++) {
        poison += CharToInt(barrel[i]) * pow(3, 5 - i - 1);
    }

    return poison;
}

unsigned long long CheckUnsigned() {
	unsigned long long input;
	char next;

	while (true) {
		if (std::cin >> input) {
			std::cin.get(next);
			while (next == ' ') {
				std::cin.get(next);
			}

			if (next == '\n') {
				break;
			}
		}

		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Неверный формат ввода! Необходими ввести целое неотрицательное число!\n";
	}

	return input;
}

std::string CheckSystem(int system){
    std::string number;

    while(1){
        std::cin >> number;
        bool checked = true;
        for (int i = 0; i < number.size(); i++) {
            if (i == 0 && number[i] == '-'){
                continue;
            }
            if (number[i] < '0' || (number[i] > '9' && number[i] < 'A') || CharToInt(number[i]) >= system){
                checked = false;
                break;
            }
        }

        if (checked){
            break;
        }

        std::cout << "Неверный формат ввода! Необходимо ввести число в " << system << "-ой системе!\n";
    }

    return number;
}

void repeat(){
    std::cout << "Повторить решение?(y/n) ";
	char answer;
	std::cin >> answer;

	while (true) {
		if (answer == 'y') {
			std::cout << "----------------------\n";
			std::cin.ignore(10000, '\n');
			main();
			break;
		}
		else if (answer == 'n') {
			break;
		}
		else {
			std::cout << "Неверный символ!\n";
			std::cin.ignore(10000, '\n');
			std::cin >> answer;
		}
	}
}