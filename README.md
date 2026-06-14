# 🎮 C Game Projects Portfolio

Welcome to my collection of interactive CLI games built with C! This repository contains two exciting turn-based battle games that showcase game logic, strategic gameplay, and user interaction handling.

## 📚 Projects

### ⚡ Energy Duel (`example_16.c`)
A strategic two-player battle game where players manage energy points to execute powerful attacks.

**Features:**
- Light Attack (1 EP, 10 damage)
- Heavy Attack (3 EP, 35 damage)
- Charge Action (gain 2 EP, free action)
- Turn-based combat system
- Real-time HP and EP tracking

**How to Run:**
```bash
gcc example_16.c -o energy_duel
./energy_duel
```

---

### 🔥 Element Duel (`example_17.c`)
An advanced two-player strategy game featuring three elemental stances with dynamic difficulty scaling.

**Features:**
- 3 Elemental Stances: Fire, Water, Earth
- Dynamic Difficulty Scaling:
  - Rounds 1-3: 1x Damage
  - Rounds 4-6: 1.5x Damage
  - Rounds 7+: 2x Damage (Sudden Death!)
- Strategic Counter System
- HP and Healing Mechanics
- Screen clearing for better UX

**How to Run:**
```bash
gcc example_17.c -o element_duel
./element_duel
```

---

## 🚀 Getting Started

### Prerequisites
- A C compiler (gcc, clang, or MSVC)
- Command line/Terminal

### Clone the Repository
```bash
git clone https://github.com/Syed-Zayer-Ahmad/My-Projects.git
cd My-Projects
```

### Compile and Run
Choose a game and compile it:
```bash
# Energy Duel
gcc example_16.c -o energy_duel
./energy_duel

# Element Duel
gcc example_17.c -o element_duel
./element_duel
```

---

## 📖 Game Rules

### Energy Duel Rules
1. Two-player game requiring logic and strategy
2. Both players start with 100 HP and 0 EP
3. Player 1 starts first
4. Choose attacks based on available energy
5. First player to reach 0 HP loses

### Element Duel Rules
1. Two-player game of predicting opponent's moves
2. Both players start with 100 HP
3. Each round, secretly choose a stance
4. Damage output depends on stance matchups and round progression
5. Reduce opponent's HP to 0 or below to win
6. If both reach 0 HP simultaneously, it's a TIE

---

## 💡 Learning Outcomes

These projects demonstrate:
- **C Programming Basics:** Variables, loops, conditionals, functions
- **Game Logic:** Turn-based systems, damage calculations, state management
- **User Input Handling:** Validating user choices and managing game flow
- **String Manipulation:** Storing player names and displaying formatted output
- **Strategic Thinking:** Balancing risk vs. reward in gameplay

---

## 📸 Features

✅ Colorized terminal output (ANSI color codes)
✅ Input validation and error handling
✅ Turn-based gameplay mechanics
✅ Real-time stat tracking
✅ Clear screen functionality for better UX
✅ Player vs Player local multiplayer

---

## 🎯 Future Enhancements

- [ ] Save/Load game functionality
- [ ] Difficulty levels (Easy, Medium, Hard)
- [ ] More game modes (3-player, tournament mode)
- [ ] Sound effects and visual animations
- [ ] Replay system
- [ ] Statistics tracking

---

## 👨‍💻 Author

**Syed Zayer Ahmad**
- GitHub: [@Syed-Zayer-Ahmad](https://github.com/Syed-Zayer-Ahmad)
- Email: syedzayerahmad@gmail.com

---

## 📝 License

This project is open source and available under the MIT License.

---

## 🙋 Contributing

Feel free to fork this repository and submit pull requests for any improvements!

---

**Enjoy the games! 🎮✨**
