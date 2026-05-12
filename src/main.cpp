#include <iostream>
#include <vector>

// Funkce pro součin matice a vektoru libovolné velikosti
// matrix: matice ve tvaru vector<vector<double>>
// vec: vektor, jehož délka musí odpovídat počtu sloupců matice
// návratová hodnota: výsledný vektor (počet prvků = počet řádků matice)
// pokud nejsou rozměry kompatibilní, vrací prázdný vektor
std::vector<double> multiplyMatrixVector(
    const std::vector<std::vector<double>>& matrix,
    const std::vector<double>& vec)
{
    // 1) Ověření, zda matice není prázdná
    if (matrix.empty())
    {
        return {}; // prázdný vektor
    }

    // 2) Ověření, zda první řádek není prázdný (abychom zjistili počet sloupců)
    std::size_t cols = matrix[0].size();
    if (cols == 0)
    {
        return {};
    }

    // 3) Ověření, že všechny řádky mají stejný počet sloupců
    for (const auto& row : matrix)
    {
        if (row.size() != cols)
        {
            // Matice není „pravidelná“ – raději vrátíme prázdný vektor
            return {};
        }
    }

    // 4) Ověření kompatibility rozměrů:
    //    počet sloupců matice musí být stejný jako velikost vektoru
    if (cols != vec.size())
    {
        return {};
    }

    // 5) Vytvoření výsledného vektoru o velikosti počtu řádků matice
    std::size_t rows = matrix.size();
    std::vector<double> result(rows, 0.0);

    // 6) Výpočet součinu matice a vektoru
    //    pro každý řádek matice spočítáme skalární součin s vektorem
    for (std::size_t i = 0; i < rows; ++i)
    {
        double sum = 0.0;
        for (std::size_t j = 0; j < cols; ++j)
        {
            sum += matrix[i][j] * vec[j];
        }
        result[i] = sum;
    }

    return result;
}

int main()
{
    // Příklad matice 3x3
    std::vector<std::vector<double>> matrix = {
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    };

    // Vektor délky 3 – kompatibilní s počtem sloupců matice
    std::vector<double> vec = { 1.0, 0.5, -1.0 };

    // Zavoláme funkci pro součin matice a vektoru
    std::vector<double> result = multiplyMatrixVector(matrix, vec);

    // Ověříme, zda byl výpočet úspěšný (neprázdný vektor)
    if (result.empty())
    {
        std::cout << "Rozmery nejsou kompatibilni, nelze spocitat soucin." << std::endl;
    }
    else
    {
        std::cout << "Vysledny vektor: ";
        for (double v : result)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
