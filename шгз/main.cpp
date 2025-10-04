#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <cmath>
#include <iomanip>
#include <numeric>

std::map<std::string, double> load_bigram_frequencies() {
    std::map<std::string, double> freqs;
    freqs["СТ"] = 0.0118; freqs["НО"] = 0.0108; freqs["ЕН"] = 0.0101; freqs["ТО"] = 0.0094;
    freqs["НА"] = 0.0088; freqs["ОВ"] = 0.0084; freqs["НИ"] = 0.0076; freqs["РА"] = 0.0073;
    freqs["ВО"] = 0.0069; freqs["КО"] = 0.0064; freqs["ОЛ"] = 0.0063; freqs["ОС"] = 0.0060;
    freqs["ПО"] = 0.0058; freqs["ГО"] = 0.0057; freqs["ЕС"] = 0.0056; freqs["КА"] = 0.0055;
    freqs["ЕР"] = 0.0054; freqs["ПЕ"] = 0.0053; freqs["ОН"] = 0.0052; freqs["РО"] = 0.0051;
    freqs["АЛ"] = 0.0050; freqs["НЕ"] = 0.0049; freqs["ОТ"] = 0.0048; freqs["ОД"] = 0.0047;
    freqs["СК"] = 0.0047; freqs["СЛ"] = 0.0046; freqs["АН"] = 0.0045; freqs["ЧТ"] = 0.0044;
    freqs["ЕЛ"] = 0.0043; freqs["ВА"] = 0.0042; freqs["КИ"] = 0.0041; freqs["ВЕ"] = 0.0040;
    freqs["РЕ"] = 0.0040; freqs["ДА"] = 0.0039; freqs["ПРО"] = 0.0038; freqs["ЗА"] = 0.0037;
    freqs["ОГО"] = 0.0037; freqs["ПР"] = 0.0036; freqs["ЛИ"] = 0.0035; freqs["ТА"] = 0.0035;
    freqs["МЕ"] = 0.0034; freqs["ОК"] = 0.0033; freqs["ОМ"] = 0.0032; freqs["ОЖ"] = 0.0032;
    return freqs;
}

double score(const std::string& plaintext, const std::map<std::string, double>& bigram_freq, double log_floor_prob) {
    double current_score = 0.0;
    for (size_t i = 0; i < plaintext.length() - 1; ++i) {
        std::string bigram = plaintext.substr(i, 2);
        auto it = bigram_freq.find(bigram);
        if (it != bigram_freq.end()) {
            current_score += log(it->second);
        }
        else {
            current_score += log_floor_prob;
        }
    }
    return current_score;
}

void print_formatted(const std::string& text, int line_length) {
    for (size_t i = 0; i < text.length(); i += line_length) {
        std::cout << text.substr(i, line_length) << std::endl;
    }
}

std::string decrypt(const std::string& ciphertext, const std::vector<int>& key) {
    const int block_size = key.size();
    if (block_size == 0) return "";

    std::string plaintext = "";
    plaintext.reserve(ciphertext.length());

    std::vector<int> inv_key(block_size);
    for (int i = 0; i < block_size; ++i) {
        inv_key[key[i]] = i;
    }


    for (size_t i = 0; i < ciphertext.length(); i += block_size) {
        std::string cipher_block = ciphertext.substr(i, block_size);
        std::string plain_block(cipher_block.length(), ' ');


        for (size_t j = 0; j < cipher_block.length(); ++j) {
            plain_block[inv_key[j]] = cipher_block[j];
        }
        plaintext += plain_block;
    }

    return plaintext;
}


int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    //cюда ввести шт в ciphertext
    std::string ciphertext = "КВРСАЫОООРВОВСПНЕМСМЗНСАИТУАЛЧЯЕДЕЖРАДВЛЙЧДУЙСМОВЕООЛТВЕОКПОИУПУИДРНСКУЛОГААНЖСРЕУЕНЕЖМЕСАЕОИПРРОРТИЕОЕОИДНВШКЖЕНБИСЦПЕТЬИУПООРЛЕКЕТТОЕКАСАИГАККЛЕКЕОСАЛНВИОЛВГДЧАОЗЕАТРТЬСММЫКОДЕОМЛООВИЕЛКАЧКУАОГЗЛЕШВУВОЗАМАГЛАВТЛУОИДОРАИГРДКАГМВЯКЛЖСАРИУНСДОЧОТЦЙАЩКЗОАЯОБРКАСИПНТЫЫОСУТАНАГЛНЯЬМОЯЛДНСООЕЫМТБЙРЕАЛУХЮМОРЬОАЕКАЛЕШКЙАСЛНЕОДРСООЕАЕМЗВЖТЧГМВУИОРДИДВОНУКВЕАГЙТЕНСРЖРАЕАИЕНОЛЗЛЫСЧРПСЕЖАЕЬТЕЧОТБАУЛЛИНМЫОНКЕДОВНКАЛЧАВИНЕООЛАТЧПССАНТТОРОЯЕЛИОАКБАВННРНСТАКАЕАШОЬАЯПВЕНОАИВТУКМШКЛУУСЫТНЖТРОЕЕЗИТМЕСЕЧАНЕВ";
    const int ROW_LENGTH = 19;

    auto russian_bigram_freq = load_bigram_frequencies();
    const double log_floor_prob = log(1.0 / (32 * 32 * 1000.0));

    std::random_device rd;
    std::mt19937 g(rd());

    std::vector<int> current_key(ROW_LENGTH);
    std::iota(current_key.begin(), current_key.end(), 0);
    std::shuffle(current_key.begin(), current_key.end(), g);

    std::string current_plaintext = decrypt(ciphertext, current_key);
    double current_score = score(current_plaintext, russian_bigram_freq, log_floor_prob);

    std::vector<int> best_key = current_key;
    double best_score = current_score;

    double temperature = 100.0;
    double cooling_rate = 0.9995;
    int iterations_per_temp = 5000;

    std::cout << "Starting decryption process for Simple Block Permutation Cipher...\n" << std::endl;

    int progress_counter = 0;
    while (temperature > 0.01) {
        for (int i = 0; i < iterations_per_temp; ++i) {
            std::vector<int> new_key = current_key;


            std::uniform_int_distribution<> dist(0, ROW_LENGTH - 1);
            int pos1 = dist(g);
            int pos2 = dist(g);
            if (pos1 == pos2) continue;

            int val1 = -1, val2 = -1;
            for (int k = 0; k < ROW_LENGTH; ++k) {
                if (new_key[k] == pos1) val1 = k;
                if (new_key[k] == pos2) val2 = k;
            }
            if (val1 != -1 && val2 != -1) {
                std::swap(new_key[val1], new_key[val2]);
            }
            else {
                continue;
            }


            std::string new_plaintext = decrypt(ciphertext, new_key);
            double new_score = score(new_plaintext, russian_bigram_freq, log_floor_prob);

            if (new_score > current_score || exp((new_score - current_score) / temperature) > std::uniform_real_distribution<>(0.0, 1.0)(g)) {
                current_key = new_key;
                current_score = new_score;
            }

            if (current_score > best_score) {
                best_score = current_score;
                best_key = current_key;
            }
        }
        temperature *= cooling_rate;

        progress_counter++;
        if (progress_counter % 100 == 0) {
            std::cout << "Temp: " << std::fixed << std::setprecision(2) << temperature
                << ", Best Score: " << best_score << std::endl;
            print_formatted(decrypt(ciphertext, best_key), ROW_LENGTH);
            std::cout << std::endl;
        }
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Final Decryption (best key found):" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    print_formatted(decrypt(ciphertext, best_key), ROW_LENGTH);

    std::cout << "\nBest key (encryption permutation): ";
    for (int k : best_key) {
        std::cout << k << " ";
    }
    std::cout << std::endl;

    return 0;
}
