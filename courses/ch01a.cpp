#include <iostream>
#include <string>

//#define IS_DEBUG

using namespace std;

struct NilaiPeserta {
    int S1, S2, S3;
    string ID;

    #ifdef IS_DEBUG
    void print() {
        cout << ID << ": " << S1 << " " << S2 << " " << S3 << endl;
    }
    #endif
};

void testAdd(
    NilaiPeserta daftarNilaiPesertaTop[], 
    int size, 
    NilaiPeserta nilaiPeserta, 
    int i,
    int l
) {
    if (i >= size) {
        return;
    }

    #ifdef IS_DEBUG
    cout << "LOOP " << i << endl;
    #endif

    if (l == 0 && i == 0) {
        daftarNilaiPesertaTop[i] = nilaiPeserta;

        #ifdef IS_DEBUG
        cout << "REGISTER ";
        nilaiPeserta.print();
        #endif

        return;
    }
    
    NilaiPeserta nilaiPesertaTop = daftarNilaiPesertaTop[i];

    #ifdef IS_DEBUG
    cout << "Nilai Peserta ";
    nilaiPeserta.print();
    cout << "Nilai Peserta Top ";
    nilaiPesertaTop.print();
    #endif

    if (nilaiPesertaTop.S3 < nilaiPeserta.S3) {
        testAdd(daftarNilaiPesertaTop, size, nilaiPesertaTop, i + 1, l);

        daftarNilaiPesertaTop[i] = nilaiPeserta;

        #ifdef IS_DEBUG
        if (i != 0) return;

        cout << "CURRENT" << endl;
        for (int l = 0; l < size; l++) {
            cout << l << " ";
            daftarNilaiPesertaTop[l].print();
        }
        #endif    

        return;
    } else if (nilaiPesertaTop.S3 == nilaiPeserta.S3 && nilaiPesertaTop.S2 < nilaiPeserta.S2) {
        testAdd(daftarNilaiPesertaTop, size, nilaiPesertaTop, i + 1, l);
        
        daftarNilaiPesertaTop[i] = nilaiPeserta;

        #ifdef IS_DEBUG
        if (i != 0) return;

        cout << "CURRENT" << endl;
        for (int l = 0; l < size; l++) {
            cout << l << " ";
            daftarNilaiPesertaTop[l].print();
        }
        #endif    

        return;
    } else if (nilaiPesertaTop.S3 == nilaiPeserta.S3 && nilaiPesertaTop.S2 == nilaiPeserta.S2 && nilaiPesertaTop.S1 < nilaiPeserta.S1) {
        testAdd(daftarNilaiPesertaTop, size, nilaiPesertaTop, i + 1, l);
        
        daftarNilaiPesertaTop[i] = nilaiPeserta;

        #ifdef IS_DEBUG
        if (i != 0) return;

        cout << "CURRENT" << endl;
        for (int l = 0; l < size; l++) {
            cout << l << " ";
            daftarNilaiPesertaTop[l].print();
        }
        #endif    

        return;
    } else {
        testAdd(daftarNilaiPesertaTop, size, nilaiPeserta, i + 1, l);
    }

    #ifdef IS_DEBUG
    if (i != 0) return;

    cout << "CURRENT" << endl;
    for (int l = 0; l < size; l++) {
        cout << l << " ";
        daftarNilaiPesertaTop[l].print();
    }
    #endif
}

int main() {
    int T;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int N, M;
        string ID;
        
        cin >> N >> M >> ID;
        
        NilaiPeserta daftarNilaiPesertaTop[M];
        int posisiPesertaYangDiinginkan;
        
        for (int l = 0; l < N; l++) {
            int S1, S2, S3;
            string ID;
            
            cin >> ID >> S1 >> S2 >> S3;
            
            NilaiPeserta nilaiPeserta = NilaiPeserta{
                .S1 = S1,
                .S2 = S2,
                .S3 = S3,
                .ID = ID,
            };
            

            #ifdef IS_DEBUG
            cout << "ITERATE " << l << endl;
            #endif
            testAdd(daftarNilaiPesertaTop, M, nilaiPeserta, 0, l);
        }
        
        bool sudahKetemu = false;

        #ifdef IS_DEBUG
        cout << "FINAL" << endl;

        for (int l = 0; l < M; l++) {
            cout << l << " ";
            daftarNilaiPesertaTop[l].print();
        }
        #endif
        
        for (int l = 0; l < M; l++) {
            if (daftarNilaiPesertaTop[l].ID == ID) {
                sudahKetemu = true;
                
                printf("YA\n");
                
                break;
            }
        }
        
        if (!sudahKetemu) {
            printf("TIDAK\n");
        }
    }
    
    return 0;
}