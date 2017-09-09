//#include "ArcadeSimulator.h"
//
//ArcadeSimulator::ArcadeSimulator(int tnum, int tcap, int mplayers, int mdur) {
//    tableNumber = tnum;
//    tableCapacity = tcap;
//    maxPlayers = mplayers;
//    maxDuration = mdur;
//
//    initialize_Tables(tableNumber, tableCapacity);
//    initialize_Players(maxPlayers);
//
//    scheduler = new Scheduler(maxDuration);
//    tracker = new StatsTracker();
//}
//
//ArcadeSimulator::~ArcadeSimulator() {
//    delete tracker;
//    delete scheduler;
//    
//    for (auto p : players)
//	   delete p;
//
//    for (auto t : tables)
//	   delete t;
//
//}
//
//void ArcadeSimulator::set_OutputDirectory(string dir) {
//    outDirectory = dir;
//}
//
//void ArcadeSimulator::run() {}
//
//void ArcadeSimulator::printSettings() {
//    cout << "Table Number: " << tableNumber << endl;
//    cout << "Table Capacity: " << tableCapacity << endl;
//    cout << "Maximum Players: " << maxPlayers << endl;
//    cout << "Maximum Duration (Turns): " << maxDuration << endl;
//}
//
//void ArcadeSimulator::printStats() {
//    scheduler->print();
//}
//
//void ArcadeSimulator::save() {}
//
//void ArcadeSimulator::initialize_Tables(int tnum, int tcap) {
//    for (int i = 0; i < tnum; i++) {
//	   tables.push_back(new Table(tcap));
//    }
//}
//
//void ArcadeSimulator::initialize_Players(int mplayers) {
//    for (int i = 0; i < mplayers; i++) {
//	   players.push_back(new Player());
//    }
//}