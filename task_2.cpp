// Reverse Integer
//https://leetcode.com/problems/reverse-integer/submissions/1872586372/

class Solution {
public:
    int reverse(int x) {
        // Переменная для хранения результата
        int reversed = 0;
        
        // Обрабатываем число до тех пор, пока оно не станет равным 0
        while (x != 0) {
            // Получаем последнюю цифру числа
            int digit = x % 10;
            
            // Уменьшаем x, отбрасывая последнюю цифру
            x /= 10;
            
            // Проверка на переполнение перед умножением на 10
            // INT_MAX = 2147483647, INT_MIN = -2147483648
            if (reversed > INT_MAX / 10 || 
                (reversed == INT_MAX / 10 && digit > 7)) {
                // Если reversed * 10 выйдет за границы INT_MAX
                return 0;
            }
            if (reversed < INT_MIN / 10 || 
                (reversed == INT_MIN / 10 && digit < -8)) {
                // Если reversed * 10 выйдет за границы INT_MIN
                return 0;
            }
            
            // Добавляем цифру к результату (сдвигаем на разряд влево и добавляем цифру)
            reversed = reversed * 10 + digit;
        }
        
        // Возвращаем перевернутое число
        return reversed;
    }
};
