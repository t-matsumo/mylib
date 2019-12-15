fun binarySearch () {
    val MOD = 1000000007L
    val MAX = 3000
    val combination = Array<LongArray>(MAX) { LongArray(MAX) }
    combination[0][0] = 1
    for (i in 1 until MAX) {
        for (j in 0..i) {
            val left = if (j - 1 >= 0) combination[i - 1][j - 1] else 0
            val right = combination[i - 1][j]
            combination[i][j] = (left + right) % MOD
        }
    }
}
