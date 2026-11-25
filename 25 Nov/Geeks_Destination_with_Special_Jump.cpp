// Date: 25 Nov 2026
// Problem: Geek's Destination with Special Jump
// Difficulty: Hard

class Solution {
  public:
    int minTime(int a, int b, int d, int l, int r) {
        const long long MOD = 1000000007LL;
        const long long INV2 = 500000004LL;

        long long A = a, B = b, D = d, L = l, R = r;
        long long M = A - B; // Net forward progress per full cycle

        // Minimum time without using the special jump
        long long k0 = (D - A + M - 1) / M;
        long long t_no_jump = D + 2 * B * k0;

        // Exact minimum time to first reach position p (p >= 1) via normal movement
        auto reachTime = [&](long long p) -> long long {
            if (p <= A) return p;
            long long c = (p - A + M - 1) / M;
            return p + 2 * B * c;
        };

        // Binary search for smallest j in [L, R] where jumping is strictly faster
        long long low = L, high = R, first_jump_j = R + 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (1 + reachTime(D - mid) < t_no_jump) {
                first_jump_j = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Helper: sum of floor(x / M) for x in [0, N] modulo MOD
        auto sumFloor = [&](long long N) -> long long {
            if (N < 0) return 0;
            long long q = N / M;
            long long rem = N % M;

            long long q_mod = q % MOD;
            long long q_prev_mod = (q - 1 + MOD) % MOD;
            long long full_blocks = (M % MOD) * q_mod % MOD * q_prev_mod % MOD * INV2 % MOD;
            long long partial_block = ((rem + 1) % MOD) * q_mod % MOD;

            return (full_blocks + partial_block) % MOD;
        };

        // Helper: sum of integers in [xL, xR] (assuming xL <= xR) modulo MOD
        auto sumRange = [&](long long xL, long long xR) -> long long {
            if (xL > xR) return 0;
            long long cnt = (xR - xL + 1) % MOD;
            long long s = ((xL % MOD) + (xR % MOD)) % MOD;
            return cnt * s % MOD * INV2 % MOD;
        };

        long long ans = 0;

        // 1. Range where t_no_jump is optimal: j in [L, first_jump_j - 1]
        long long cnt_no_jump = first_jump_j - L;
        if (cnt_no_jump > 0) {
            ans = (ans + (cnt_no_jump % MOD) * (t_no_jump % MOD)) % MOD;
        }

        // 2. Range where jumping is optimal: j in [first_jump_j, R]
        // Corresponding jump-off positions p = D - j lie in [pL, pR]
        if (first_jump_j <= R) {
            long long pL = D - R;
            long long pR = D - first_jump_j;
            long long cnt_jump = pR - pL + 1;

            // +1 second for each jump
            ans = (ans + (cnt_jump % MOD)) % MOD;

            // Part A: p <= A -> reachTime(p) = p
            long long r1 = std::min(pR, A);
            if (pL <= r1) {
                ans = (ans + sumRange(pL, r1)) % MOD;
            }

            // Part B: p > A -> reachTime(p) = p + 2 * B * ceil((p - A) / M)
            long long l2 = std::max(pL, A + 1);
            if (l2 <= pR) {
                ans = (ans + sumRange(l2, pR)) % MOD;

                long long yL = (l2 - A) + M - 1;
                long long yR = (pR - A) + M - 1;
                long long ceil_sum = (sumFloor(yR) - sumFloor(yL - 1) + MOD) % MOD;

                ans = (ans + (2 * B % MOD) * ceil_sum) % MOD;
            }
        }

        return static_cast<int>(ans);
    }
};
