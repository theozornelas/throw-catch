#ifndef ENTRY_H
#define ENTRY_H

/**
 * @brief  This class describes a key-value pair
 *
 * @author Ethan Slattery
 * @date   12APR2016
 */
template <typename K, typename V>
class Entry {
public:
    /*** Enum for the state of the entry ***/
    enum STATE { OCCUPIED, EMPTY, DELETED };

    /// Default Constructor sets to empty values
    Entry() : key_(), value_(), state_(EMPTY) {}
    /// Non-Default consturctor sets key and value
    Entry(const K& k, const V& v) : key_(k), value_(v), state_(OCCUPIED) {}

    /*** GET AND SET METHODS ***/
    /// RETURNS the KEY of the entry
    const K& key() const { return key_; }
    K& key() { return key_; }
    /// SETS the KEY of the value
    void setKey(const K& k) { key_ = k; }
    /// RETURNS the VALUE of the entry
    const V& value() const { return value_; }
    V& value() { return value_; }
    /// SETS the VALUE of the entry, and changes the state to OCCUPIED
    void setValue(const V& v) { value_ = v; state_ = OCCUPIED; }
    /// CLEARS the entry and set to DELETED state
    void clear() { if(state_== OCCUPIED){ state_ = DELETED;} }

    /*** UTILITY METHODS ***/
    /// returns the state of the entry
    STATE state() const { return state_; }
    /// returns TRUE if the entry is empty
    bool empty() const { return state_ == EMPTY; }
    /// returns TRUE if the entry was deleted
    bool deleted() const { return state_ == DELETED; }

    /*** OVERLOADS ***/
    friend std::ostream &operator<<(std::ostream &output, const Entry &obj){
        output << "[" << obj.key_ << ", " << obj.value_ << "]";
        return output;
    }

    /*** COMPARISON OVERLOADS***/
    bool operator<(const Entry& that)  const { return (this->key_ < that.key_); }
    bool operator>(const Entry& that)  const { return (this->key_ > that.key_); }
    bool operator<=(const Entry& that) const { return (this->key_ <= that.key_); }
    bool operator>=(const Entry& that) const { return (this->key_ >= that.key_); }
    bool operator==(const Entry& that) const { return (this->key_ == that.key_); }
    bool operator!=(const Entry& that) const { return (this->key_ != that.key_); }

private:
    K     key_;     //< Key
    V     value_;   //< Value
    STATE state_;   //< the state of the entry
};

#endif // ENTRY_H

