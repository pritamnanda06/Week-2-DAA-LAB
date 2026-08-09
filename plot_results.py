import numpy as np
import matplotlib.pyplot as plt

n = np.array([1000, 2000, 4000, 8000, 16000])

f_1 = np.ones_like(n)
f_logn = np.log2(n)
f_n = n

# sharex and sharey synchronize axes and remove redundant inner labels
fig, axes = plt.subplots(2, 2, figsize=(13, 9), sharex=True, sharey=True)

# 1. Search Operation
axes[0, 0].plot(n, f_n, 'o-', label='Unsorted Array / Lists: O(n)', color='tab:blue', lw=2)
axes[0, 0].plot(n, f_logn, 's--', label='Sorted Array: O(log n)', color='tab:orange', lw=2)
axes[0, 0].set_title('1. Search Operation', fontweight='bold')

# 2. Insert Operation
axes[0, 1].plot(n, f_1, '^-', label='Unsorted Structures: O(1)', color='tab:green', lw=2)
axes[0, 1].plot(n, f_n, 's--', label='Sorted Structures: O(n)', color='tab:red', lw=2)
axes[0, 1].set_title('2. Insert Operation', fontweight='bold')

# 3. Delete Operation
axes[1, 0].plot(n, f_1, '^-', label='Doubly Unsorted / Sorted: O(1)', color='tab:purple', lw=2)
axes[1, 0].plot(n, f_n, 'o--', label='Singly Unsorted / Sorted Array: O(n)', color='tab:brown', lw=2)
axes[1, 0].set_title('3. Delete Operation', fontweight='bold')

# 4. Min, Max, Predecessor, Successor
axes[1, 1].plot(n, f_1, 's-', label='Sorted Array / Doubly Sorted: O(1)', color='tab:olive', lw=2)
axes[1, 1].plot(n, f_n, 'o--', label='Unsorted Structures: O(n)', color='tab:cyan', lw=2)
axes[1, 1].set_title('4. Min / Max / Pred / Succ Operations', fontweight='bold')

for ax in axes.flat:
    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.grid(True, which="both", ls="--", alpha=0.5)
    ax.legend(fontsize=9, loc='upper left')

# Shared global axis labels positioned outside the plot grid
fig.supxlabel('Input Size N (Log Scale)', fontsize=12, fontweight='bold')
fig.supylabel('Steps / Growth (Log Scale)', fontsize=12, fontweight='bold')

plt.suptitle('Asymptotic Growth Validation for Dictionary Operations', fontsize=15, fontweight='bold')
plt.tight_layout()
plt.savefig('dictionary_complexity_final_clean.png', dpi=300)
plt.show()