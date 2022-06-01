# File_encrupt
 File encryption/decryption system based on 3DES, blowfish, MD5  Usage: 
 1. Select the file to be encrypted; 
 2. Select the encryption method: single encryption method/double encryption method 
 3. Execute encryption  Note: One-time encryption can use 3DES or blowfish respectively, and continuous encryption uses 3DES first and then blowfish. In addition to the above symmetric encryption algorithm, driver encryption can also be used. There are special switches on the interface.  
 
There are problems: 
1. 3DES encryption does not match blowfish; 
2. It is unreasonable to append the MD5 check value to the end of the ciphertext; 
3. When two encryptions are used, the decryption sequence needs to be opposite to the encryption during decryption.

To be improved: 
1. Modify the key storage method to increase MySQL storage; 
2. It is better to mix the two encryption methods into a single encryption;
3. Optimize the code to improve the speed, try to use multi-threading or data segmentation optimization.
