#include <string>
#include <iostream>

using namespace std;

struct HashTableNode {
    string key;
    int value;
    HashTableNode(string _key, int _value) : key(_key), value(_value){}
};

class HashTable {
    public:
        virtual void insert(string key, int value) = 0;
        virtual bool exist(string key) = 0;
        virtual int get(string key) = 0;
        virtual void remove(string key) = 0;
        virtual int getCount() = 0;
};



class HashTableImp : public HashTable {
    private:
        HashTableNode ** table;
        int tableSize;
        int count;

        // Ref: https://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-15.html
        int hash(string key) {
            int h = 0;
            for (int i = 0; i < key.length(); i++)
                h = 31 * h + int(key[i]);
            return h;
        }

        int getIndex(string key) {
            int hashValue = this->hash(key);
            return abs(hashValue) % this->tableSize;
        }          
    public:
        HashTableImp(int _size) {
            this->tableSize = _size;
            this->count = 0;
            this->table = new HashTableNode*[tableSize];

            for (int i = 0; i < this->tableSize; i++)
            {
                table[i] = NULL;
            }
        }

        bool isFull() {
            return count==tableSize;
        }

        int getCount(){
            return this->count;
        }

        void insert(string key, int value) {
            int index = getIndex(key);
            bool inserted = false;
            int attempt = 1;

            while(!isFull() && !inserted){
                if(this->table[index]==NULL) {
                    this->table[index] = new HashTableNode(key,value);
                    this->count++;
                    inserted = true;
                } else{
                    if(this->table[index]->key==key) {
                        this->table[index]->value = value;
                        inserted = true;
                    } else {
                        index = abs(this->hash(key) + attempt * this->hash(key)) % tableSize; //double-hashing
                        attempt++;
                    }
                }
            }
        }

        bool exist(string key) {
            int index = getIndex(key);
            bool finished = false;
            bool found = false;
            int attempt = 1;

            while(!finished){
                if(this->table[index]==NULL) {
                    found = false;
                    finished = true;
                } else{
                    if(this->table[index]->key==key) {
                        found = true;
                        finished = true;
                    } else {
                        index = abs(this->hash(key) + attempt * this->hash(key)) % tableSize; //double-hashing
                        attempt++;
                    }
                }
            }
        }

        int get(string key) {
            int retValue = 0;
            int index = getIndex(key);
            bool finished = false;
            int attempt = 1;
            bool exists = exist(key);

            while(exists && !finished){
                if(this->table[index]->key==key) {
                    retValue = this->table[index]->value;
                    finished = true;
                } else{
                    index = abs(this->hash(key) + attempt * this->hash(key)) % tableSize; //double-hashing
                    attempt++;
                }
            }

            return retValue;
        }

        void remove(string key) {
            int index = getIndex(key);
            bool deleted = false;
            int attempt = 1;
            bool exists = exist(key);

            while(exists && !deleted){
                if(this->table[index]->key==key) {
                    delete this->table[index];
                    this->table[index] = NULL;
                    this->count--;
                    deleted = true;
                } else{
                    index = abs(this->hash(key) + attempt * this->hash(key)) % tableSize; //double-hashing
                    attempt++;
                }
            }

        }
};

int main() {

    int N;
    cin >> N;
    HashTable *hashTable = new HashTableImp(N*2);
    for (int i = 0; i < N; i++) {
        string mail;
        cin >> mail;
        !hashTable->exist(mail) ? hashTable->insert(mail, 1) : hashTable->insert(mail, hashTable->get(mail) + 1);
    }

    cout << hashTable->getCount();

    return 0;

}