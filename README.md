# BACH_demo

An open-source implementation for BACH: <u>B</u>ridging <u>A</u>djacency List and <u>C</u>SR Format using LSM-Trees for <u>H</u>GTAP Workloads.
conference paper: https://www.vldb.org/pvldb/vol18/p1509-miao.pdf (VLDB 2025 accepted)




## Abstract
Modern data-intensive applications require databases that support fast analytical processing on massive dynamic graphs in real time, while simultaneously providing transactional guarantees for modifying graph-based objects (i.e., edges, vertices and their properties).

Achieving efficient Hybrid Graph Transactional/Analytical Processing (HGTAP) in a database poses significant challenges due to the simultaneous requirements of high operation throughput, high data freshness, and high performance isolation when processing concurrent read/write queries on intricate graph topology.

Existing disk-based graph databases fail to meet these requirements at the same time due to their inclined data layout, such as the transactional storage based on adjacency list and the analytical storage based on CSR (compressed sparse row) format.

To address these challenges, we present BACH (Bridging Adjacency List and CSR Format using LSM (Log-Structured Merge)-Trees for HGTAP Workloads) to fill the gaps in HGTAP databases.

BACH expands the design space of traditional LSM-Trees to accommodate different graph data layouts in different levels. The compaction process is further extended to seamlessly transform the graph layout from the TP-friendly adjacency list to the AP-friendly CSR format through the data propagation to deeper levels in the LSM-Tree.

A novel compaction policy, namely elastic merge, is carefully devised to adapt to diverse workloads and the skew vertex degree distribution on graph data.

These techniques lead to a Graph-aware Real-time (GR)-LSM-Tree, which can provide consistently efficient data access for diverse workloads throughout the entire lifespan of graph objects.

Then, a lightweight multi-version scheme is devised for the GR-LSM-Tree to accelerate the concurrent read/write processing with the snapshot isolation guarantee.

Comprehensive experiments demonstrate that BACH significantly outperforms other disk-based graph database solutions in HGTAP workloads.


## Building
G++12 and [Folly](https://github.com/facebook/folly) needed.
```bash
mkdir build && cd build
cmake ..
make -j 8
```

## Structure
- `include/BACH` the header file of BACH.
- `include/dynamic_bitset` [dynamic_bitset](https://github.com/pinam45/dynamic_bitset) library
- `include/folly` [Folly](https://github.com/facebook/folly) library
- `src` the source code of BACH.

## Benchmark

We used the following branches of gfe_driver for system testing which can be found in the following repository:

https://github.com/2600254/gfe_driver/

The executable files for the SNB test can be found in the Releases.
Run the following command to start SNB server:

```bash
mkdir server_log
TZ=UTC ./snb_server server_log /path/to/social_network 9090
```

## Usage in your own work

```c++
#include "include/BACH/BACH.h"
```

Alternatively, you can use dynamic library:

```c++
#include "bind/BACH.h"
```

Then add the linking options during building:
```bash
-lbach -L/path/to/BACH_demo/build 
```
