// Two Sum
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Создаем хеш-таблицу для хранения чисел и их индексов
        // Ключ: число из массива, Значение: индекс этого числа
        unordered_map<int, int> numMap;
        
        // Проходим по всем элементам массива
        for (int i = 0; i < nums.size(); i++) {
            // Вычисляем, какое число нам нужно для достижения target
            // complement = target - текущее число
            int complement = target - nums[i];
            
            // Проверяем, есть ли нужное число (complement) в хеш-таблице
            // find() ищет ключ, если не находит - возвращает end()
            if (numMap.find(complement) != numMap.end()) {
                // Если нашли complement в таблице, возвращаем индексы:
                // 1) индекс complement (хранится в numMap[complement])
                // 2) текущий индекс i
                return {numMap[complement], i};
            }
            
            // Если complement не найден, добавляем текущее число в таблицу
            // Ключ: текущее число (nums[i]), Значение: текущий индекс (i)
            numMap[nums[i]] = i;
        }
        
        // Хотя по условию всегда есть решение, возвращаем пустой вектор
        // на случай, если решение не найдено (для корректности компиляции)
        return {};
    }
};
