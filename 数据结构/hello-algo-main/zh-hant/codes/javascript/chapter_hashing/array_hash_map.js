/**
 * File: array_hash_map.js
 * Created Time: 2022-12-26
 * Author: Justin (xiefahit@gmail.com)
 */

/* 鍵值對 Number -> String */
class Pair {
    constructor(key, val) {
        this.key = key;
        this.val = val;
    }
}

/* 基於陣列實現的雜湊表 */
class ArrayHashMap {
    #buckets;
    constructor() {
        // 初始化陣列，包含 100 個桶
        this.#buckets = new Array(100).fill(null);
    }

    /* 雜湊函式 */
    #hashFunc(key) {
        return key % 100;
    }

    /* 查詢操作 */
    get(key) {
        let index = this.#hashFunc(key);
        let pair = this.#buckets[index];
        if (pair === null) return null;
        return pair.val;
    }

    /* 新增操作 */
    set(key, val) {
        let index = this.#hashFunc(key);
        this.#buckets[index] = new Pair(key, val);
    }

    /* 刪除操作 */
    delete(key) {
        let index = this.#hashFunc(key);
        // 置為 null ，代表刪除
        this.#buckets[index] = null;
    }

    /* 獲取所有鍵值對 */
    entries() {
        let arr = [];
        for (let i = 0; i < this.#buckets.length; i++) {
            if (this.#buckets[i]) {
                arr.push(this.#buckets[i]);
            }
        }
        return arr;
    }

    /* 獲取所有鍵 */
    keys() {
        let arr = [];
        for (let i = 0; i < this.#buckets.length; i++) {
            if (this.#buckets[i]) {
                arr.push(this.#buckets[i].key);
            }
        }
        return arr;
    }

    /* 獲取所有值 */
    values() {
        let arr = [];
        for (let i = 0; i < this.#buckets.length; i++) {
            if (this.#buckets[i]) {
                arr.push(this.#buckets[i].val);
            }
        }
        return arr;
    }

    /* 列印雜湊表 */
    print() {
        let pairSet = this.entries();
        for (const pair of pairSet) {
            console.info(`${pair.key} -> ${pair.val}`);
        }
    }
}

/* Driver Code */
/* 初始化雜湊表 */
const map = new ArrayHashMap();
/* 新增操作 */
// 在雜湊表中新增鍵值對 (key, value)
map.set(12836, '小哈');
map.set(15937, '小囉');
map.set(16750, '小算');
map.set(13276, '小法');
map.set(10583, '小鴨');
console.info('\n新增完成後，雜湊表為\nKey -> Value');
map.print();

/* 查詢操作 */
// 向雜湊表中輸入鍵 key ，得到值 value
let name = map.get(15937);
console.info('\n輸入學號 15937 ，查詢到姓名 ' + name);

/* 刪除操作 */
// 在雜湊表中刪除鍵值對 (key, value)
map.delete(10583);
console.info('\n刪除 10583 後，雜湊表為\nKey -> Value');
map.print();

/* 走訪雜湊表 */
console.info('\n走訪鍵值對 Key->Value');
for (const pair of map.entries()) {
    if (!pair) continue;
    console.info(pair.key + ' -> ' + pair.val);
}
console.info('\n單獨走訪鍵 Key');
for (const key of map.keys()) {
    console.info(key);
}
console.info('\n單獨走訪值 Value');
for (const val of map.values()) {
    console.info(val);
}
