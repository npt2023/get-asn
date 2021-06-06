# Finds all IPv4 addresses in an ASN using Wikimedia's ISP Rangefinder

curl 'https://isprangefinder.toolforge.org/hint.php?type=asn&range='{$1} -o /tmp/AS$1_tmp.txt

./pregetasn </tmp/AS$1_tmp.txt > AS$1.txt 
rm /tmp/AS$1_tmp.txt
