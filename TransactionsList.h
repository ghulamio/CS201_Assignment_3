// Ghulam Ahmed - Section 2 - 22101001

// Sorted link list of transactions for each subscriber in sorted order
class TransactionsList {
    public:
        TransactionsList();
        ~TransactionsList();
        void addTransaction( const int movieId );
        void showTransactions() const;
        void returnMovie( const int movieId );
        bool movieNotReturned( const int movieId ) const;
        bool movieEverRented( const int movieId ) const;
        int getNumTransactions() const;
        int getNumMoviesTransactions(const int movieId) const;
    private:
        struct TransactionNode {
            int movieId;
            bool returned;
            TransactionNode *next;
        };
        TransactionNode *head;
        int transactionCount;
};