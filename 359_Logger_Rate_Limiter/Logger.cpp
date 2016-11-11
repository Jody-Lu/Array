class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {}

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(record.find(message) != record.end()) {
            if(timestamp - record[message] < 10) {
                return false;
            }
            else {
                record[message] = timestamp;
                return true;
            }
        }

        record[message] = timestamp;
        return true;
    }
private:
    // <message, timestamp>
    unordered_map<string, int> record;
};