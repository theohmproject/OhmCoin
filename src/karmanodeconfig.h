
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017-2018 The OHMC 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SRC_KARMANODECONFIG_H_
#define SRC_KARMANODECONFIG_H_

#include <string>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

class CKarmanodeConfig;
extern CKarmanodeConfig karmanodeConfig;

class CKarmanodeConfig
{
public:
    class CKarmanodeEntry
    {
    private:
        std::string alias;
        std::string ip;
        std::string privKey;
        std::string txHash;
        std::string outputIndex;

    public:
        CKarmanodeEntry(std::string alias, std::string ip, std::string privKey, std::string txHash, std::string outputIndex)
        {
            this->alias = alias;
            this->ip = ip;
            this->privKey = privKey;
            this->txHash = txHash;
            this->outputIndex = outputIndex;
        }

        const std::string& getAlias() const
        {
            return alias;
        }

        void setAlias(const std::string& alias)
        {
            this->alias = alias;
        }

        const std::string& getOutputIndex() const
        {
            return outputIndex;
        }

        bool castOutputIndex(int& n);

        void setOutputIndex(const std::string& outputIndex)
        {
            this->outputIndex = outputIndex;
        }

        const std::string& getPrivKey() const
        {
            return privKey;
        }

        void setPrivKey(const std::string& privKey)
        {
            this->privKey = privKey;
        }

        const std::string& getTxHash() const
        {
            return txHash;
        }

        void setTxHash(const std::string& txHash)
        {
            this->txHash = txHash;
        }

        const std::string& getIp() const
        {
            return ip;
        }

        void setIp(const std::string& ip)
        {
            this->ip = ip;
        }
    };

    CKarmanodeConfig()
    {
        entries = std::vector<CKarmanodeEntry>();
    }

    void clear();
    bool read(std::string& strErr);
    void add(std::string alias, std::string ip, std::string privKey, std::string txHash, std::string outputIndex);

    std::vector<CKarmanodeEntry>& getEntries()
    {
        return entries;
    }

    int getCount()
    {
        int c = -1;
        BOOST_FOREACH (CKarmanodeEntry e, entries) {
            if (e.getAlias() != "") c++;
        }
        return c;
    }

private:
    std::vector<CKarmanodeEntry> entries;
};


#endif /* SRC_KARMANODECONFIG_H_ */
