const long long prime = 101; // Prime number for hashing

long long createHash(string str, int n) {
    long long hash = 0;
    for (int i = 0; i < n; i++) {
        hash += (long long)str[i] * pow(prime, i);
    }
    return hash;
}

long long reCalculateHash(string str, int oldIndex, int newIndex, long long oldHash, int patLength) {
    long long newHash = oldHash - str[oldIndex];
    newHash /= prime;
    newHash += (long long)str[newIndex] * pow(prime, patLength - 1);
    return newHash;
}

bool checkEqual(string str1, string str2, int start1, int end1, int start2, int end2) {
    if (end1 - start1 != end2 - start2)
        return false;
    while (start1 <= end1 && start2 <= end2) {
        if (str1[start1] != str2[start2])
            return false;
        start1++;
        start2++;
    }
    return true;
}

bool karpRabin(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    long long patternHash = createHash(pattern, m);
    long long textHash = createHash(text, m);

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash && checkEqual(text, pattern, i, i + m - 1, 0, m - 1)) {
           return true;
        }
        if (i < n - m) {
            textHash = reCalculateHash(text, i, i + m, textHash, m);
        }
    }
    return false;
}
