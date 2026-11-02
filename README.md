# Auction Calculator

Command line calculator just for auction house trading. Works out how much you'll actually earn after the auction house's cut, and whether crafting an item is worth it once material costs are factored in.

## Features

- **Item profit:** sale price × quantity, minus the 6% auction cut
- **Crafted item profit:** same as above, minus the total cost of every material used
- **Material cost calculator:** add any number of materials to price out a crafting project before committing
- Input validation that rejects non-numeric and non-positive values instead of crashing

## Build & Run

```bash
g++ -std=c++17 -o auction-helper main.cpp
./auction-helper
```


## Known Limitations

- Auction cut is hardcoded at 6%. Plan: make it configurable per game if desired.
- Item and material names can't contain spaces (uses `cin >>` instead of `getline`).
- The material-entry loop is duplicated between crafted profit and material cost. Plan: refactor into a shared function.
- Writing this README long after this was first created, so may go back and fix some of these...
