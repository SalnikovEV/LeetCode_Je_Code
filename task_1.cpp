// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Храним уникальные символы в текущем окне
        unordered_set<char> charSet;
        
        // Переменная для максимальной длины подстроки без повторений
        int maxLength = 0;
        
        // Левый указатель окна (начало подстроки без повторений)
        int left = 0;
        
        // Правый указатель окна проходит по всей строке
        for (int right = 0; right < s.size(); right++) {
            // Пока текущий символ уже есть в множестве (повторение)
            while (charSet.find(s[right]) != charSet.end()) {
                // Удаляем символ с левого указателя из множества
                charSet.erase(s[left]);
                // Сдвигаем левый указатель вправо (сужаем окно)
                left++;
            }
            
            // Добавляем текущий символ в множество
            charSet.insert(s[right]);
            
            // Обновляем максимальную длину
            // (right - left + 1) - длина текущей подстроки без повторений
            maxLength = max(maxLength, right - left + 1);
        }
        
        // Возвращаем максимальную длину подстроки без повторяющихся символов
        return maxLength;
    }
};
