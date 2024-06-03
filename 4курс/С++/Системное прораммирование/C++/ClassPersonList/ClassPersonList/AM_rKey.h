#ifndef AM_RKEY_H
#define AM_RKEY_H

#include <iostream>
#include <string>
#include <new>
#include <assert.h>
typedef unsigned int uint;
 
 
//ассоциативный массив(используется двоичный поиск) 
template < typename KEY, typename T >
class marray {
 
    struct info 
	{
        KEY key;
        T   data;
    };
 
private:
    info* arr;
    uint  cnt;
    uint  mem;
public:
    marray(void):arr(NULL),
                 cnt(0),
                 mem(16){}
    ~marray()
	{
        this->clear();
    }
 
    marray(const marray&);
    marray& operator = (const marray&);
 
    //добавление ключ=значение
    T* add(const KEY& key, const T& data)
	{
        uint i = _bin_find(key);
        if(! _heap_alloc_())
            return NULL;
 
        //дубликат
        if(key == arr[i].key)
            return NULL;
        
        if(i < cnt){
            info* pb = arr + cnt;
            info* pa = arr + i;
            for(;pb > pa; --pb)
                *pb = *(pb - 1); 
        }
        arr[i].key  = key;
        arr[i].data = data;
        
        ++cnt;
        return &arr[i].data;
    }
 
    //удаление данных по-ключу
    void remove(const KEY& key)
	{
        uint i = _bfind_info(key);
        if(i != (uint)-1){
            --cnt;
            info* pa = arr + i;
            info* pb = arr + cnt;
            for(;pa < pb; ++pa)
                *pa = *(pa + 1);
 
            if(! cnt)
                this->clear();
        }
    }
 
    //поиск данных по-ключу O(log(n))
    T* find(const KEY& key)
	{
        uint i = _bfind_info(key);
        return (i != (uint)-1) ? &arr[i].data : NULL;
    }
    const T* find(const KEY& key) const 
	{
        const uint i = _bfind_info(key);
        return (i != (uint)-1) ? &arr[i].data : NULL;
    }
 
    bool empty(void) const 
	{
        return (arr == NULL);
    }
 
    //кол-во элементов
    uint size(void) const 
	{
        return cnt;
    }
 
    //удаление всего массива
    void clear(void)
	{
        if(arr != NULL)
            delete[] arr;
        arr = NULL;
        cnt = 0;
        mem = 16;
    }
    
    //получение ключа по-индексу только для чтения
    const KEY& keyAt(uint i) const 
	{
        return arr[i].key;
    }
 
    //доступ к значению по-индексу
    T& valueAt(uint i) const 
	{
        return arr[i].data;
    }
 
    //получение доступа как к обычному массиву
    const T& operator [] (const KEY& key) const 
	{
        const uint i = _bfind_info(key);
 
        assert(i != (uint)-1);
        return arr[i].data;
    }
 
    T& operator [] (const KEY& key)
	{
        uint i = _bin_find(key);
        if((i < cnt) && (key == arr[i].key))
            return arr[i].data;
        
        if(_heap_alloc_()){
            if(i < cnt){
                info* pb = arr + cnt;
                info* pa = arr + i;
                for(;pb > pa; --pb)
                    *pb = *(pb - 1); 
            }
            arr[i].key  = key;
            arr[i].data = T();
            ++cnt;
        } else
            assert(false);
 
        return arr[i].data;
    }
 
private:
 
    //выделение динамической памяти для массива
    bool _heap_alloc_(void)
	{
        if(arr == NULL){
            arr = new (std::nothrow) info[mem];
            if(arr == NULL)
                return false;
        } 
		else if((cnt + 1) >= mem)
		{
            uint  tmem = cnt + mem / 2;
            info* tmp  = new (std::nothrow) info[tmem];
            if(tmp == NULL)
                return false;
            
            const info* p = arr;
            const info* e = arr + cnt;
            info* d = tmp;
            while(p != e)
                *d++ = *p++;
 
            delete[] arr;
            arr = tmp;
            mem = tmem;
        }
        return true;
    }
 
    //двоичный поиск вхождение ключа для вставки
    uint _bin_find(const KEY& key)
	{
        if(! cnt || (key < arr[0].key))
            return 0;
        else if(arr[cnt - 1].key < key)
            return cnt;
 
        uint m = 0, f = 0, l = cnt;
 
        while(f < l)
		{
            m = (f + l) >> 1;
            if(key < arr[m].key)
                l = m;
            else 
			{
                if(key == arr[m].key)
                    return m;
                f = m + 1;
            }
        }
        return f;
    }
 
    //двоичный поиск вхождения ключа
    uint _bfind_info(const KEY& key) const 
	{
        if(! cnt || (key < arr[0].key))
            return (uint)-1;
        else if(arr[cnt - 1].key < key)
            return (uint)-1;
 
        uint m = 0, f = 0, l = cnt;
 
        while(f < l){
            m = (f + l) >> 1;
            if(key < arr[m].key)
                l = m;
            else {
                if(key == arr[m].key)
                    return m;
                f = m + 1;
            }
        }
        return (uint)-1;
    }
};

#endif
/* 
int main(void){
    marray<std::string, int> arr;
 
    arr["собака"]   = 100;
    arr["волк"]     = 200;
    arr["сова"]     = 300;
    arr["дельфин"]  = 890;
 
    //найти
    int* p = arr.find("сова");
    if(p != NULL)
        *p = 1000; // изменить
 
    //удалим волка
    arr.remove("волк");
    if(arr.find("волк") == NULL)
        std::cout << "волк удалён" << std::endl;
 
    //добавим мышь
    arr.add("мышь", 90000);
 
    //вывести все элементы ключ=значение
    for(uint i = 0; i < arr.size(); ++i){
        std::cout << arr.keyAt(i)   << " = "
                  << arr.valueAt(i) << std::endl;
    }
    std::cout << std::endl;
    arr.clear();
 
    //...
 
    //задача: подсчитать кол-во одинаковых символов
    marray<char, size_t> carr;
 
    char  s[] = "AAABBBAACCCCCFCCCCC";
    char* pc  = &s[0];
    while(*pc)
        carr[*pc++]++;
 
    //вывести результат
    for(uint c = 0; c < carr.size(); ++c){
        std::cout << carr.keyAt(c)   << " = "
                  << carr.valueAt(c) << std::endl;
    }
    std::cout << std::endl;
    carr.clear();
 
    //...
 
    marray<std::string, std::string> sarr;
    sarr["Вася"] = "Геодезист";
    sarr["Петя"] = "Бетонщик";
    sarr["Юрий"] = "Кровельщик";
 
    sarr.add("Гриша", "Стропальщик");
 
    std::cout << sarr["Вася"]  << std::endl
              << sarr["Петя"]  << std::endl
              << sarr["Юрий"]  << std::endl
              << sarr["Гриша"] << std::endl;
    sarr.clear();
    return 0;
}*/
