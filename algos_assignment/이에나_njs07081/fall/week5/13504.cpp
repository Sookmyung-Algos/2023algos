using namespace std;
struct TRIE {
    bool isEnd;
    LL end_Number;
    TRIE* Child[2];

    TRIE() {
        isEnd = false;
        for (int i = 0; i < 2; i++) {
            Child[i] = nullptr;
        }
    }

    ~TRIE() {
        for (int i = 0; i < 2; i++) {
            delete Child[i];
        }
    }

    void insert_Pattern(string Pattern, LL Number) {
        TRIE* NowTrie = this;

        for (int i = 0; i < Pattern.size(); i++) {
            int Now = Pattern[i] - '0';
            if (NowTrie->Child[Now] == nullptr) {
                NowTrie->Child[Now] = new TRIE;
            }
            NowTrie = NowTrie->Child[Now];
        }

        NowTrie->isEnd = true;
        NowTrie->end_Number = Number;
    }
    
    LL query(string NowS, LL NowN) {
        TRIE* NowTrie = this;

        for (int i = 0; i < NowS.size(); i++) {
            int Now = NowS[i] - '0';

            if (NowTrie->Child[Now ^ 1] != nullptr) {
                NowTrie = NowTrie->Child[Now ^ 1];
            }
            else {
                NowTrie = NowTrie->Child[Now];
            }
        }

        return (NowTrie->end_Number ^ NowN);
    }
};

int T, N;
LL A, K;
int max_Length;
vector<int> Numbers;
vector<string> Strings;
LL Answer;

void init() {
    Numbers.clear();
    Strings.clear();
    K = 0;
    max_Length = 0;
    Answer = 0;
}

string make_String(int Number) {
    string Result = "";
    while (1) {
        if (Number == 0) {
            break;
        }
        Result = to_string(Number % 2) + Result;
        Number /= 2;
    };
    return Result;
}

void settings(TRIE* Root) {
    for (int i = 0; i <= N; i++) {
        Answer = max(Answer, Root->query(Strings[i], Numbers[i]));
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        init();
        TRIE* Root = new TRIE();
        cin >> N;
        Numbers.push_back(K);
        Strings.push_back("0");
        for (int i = 0; i < N; i++) {
            cin >> A;
            K ^= A;
            Numbers.push_back(K);
            string NewK = make_String(K);
            max_Length = max(max_Length, (int)NewK.size());
            Strings.push_back(NewK);
        };
        for (int i = 0; i <= N; i++) {
            int Sub = max_Length - (int)Strings[i].size();
            while (Sub--) {
                Strings[i] = "0" + Strings[i];
            };
            Root->insert_Pattern(Strings[i], Numbers[i]);
        }
        settings(Root);
        find_Answer();
        delete Root;
    };
}

int main() {
    FASTIO
    input();

    return 0;
}
