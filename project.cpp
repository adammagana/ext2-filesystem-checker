/*
Adam Magana, William Gains
Operating Systems, CSCI 5806
ext2 Filesystem Integrity Checker
*/

#include <iostream>
#include <math.h>

using namespace std;

//Declare SUPERBLOCK struct type
struct SUPERBLOCK {
       int s_inodes_count;
       int s_blocks_count;
       int s_r_blocks_count;
       int s_free_blocks_count;
       int s_free_inodes_count;
       int s_first_data_block;
       int s_log_block_size;
       int s_log_frag_size;
       int s_blocks_per_group;
       int s_frags_per_group;
       int s_inodes_per_group;
       int s_mtime;
       int s_wtime;
       short s_mnt_count;
       short s_max_mnt_count;
       short s_magic;
       short s_state;
       short s_errors;
       short s_minor_rev_level;
       int s_lastcheck;
       int s_checkinterval;
       int s_creator_os;
       int s_rev_level;
       short s_def_resuid;
       short s_des_resgid;

       int s_first_ino;
       short s_inode_size;
       short s_block_group_nr;
       int s_feature_compat;
       int s_feature_incompat;
       int s_feature_ro_compat;
};

//Declare block descriptor struct type
struct BLOCKDESCRIPTOR {
      int bg_block_bitmap;
      int bg_inode_bitmap;
      int bg_inode_table;
      short bg_free_blocks_count;
      short bg_free_inodes_count;
      short bg_used_dirs_count;
};

//Assigns a block descriptor's variables
void readBlockDescriptor(FILE * fs, BLOCKDESCRIPTOR &blockDescriptor) {
     //Declarations
     int * intBuffer = new int;
     short * shortBuffer = new short;

     //Read and assign values
     fread(intBuffer,4,1,fs);
     blockDescriptor.bg_block_bitmap = *intBuffer;

     fread(intBuffer,4,1,fs);
     blockDescriptor.bg_inode_bitmap = *intBuffer;

     fread(intBuffer,4,1,fs);
     blockDescriptor.bg_inode_table = *intBuffer;

     fread(shortBuffer,2,1,fs);
     blockDescriptor.bg_free_blocks_count = *shortBuffer;

     fread(shortBuffer,2,1,fs);
     blockDescriptor.bg_free_inodes_count = *shortBuffer;

     fread(shortBuffer,2,1,fs);
     blockDescriptor.bg_used_dirs_count = *shortBuffer;
}

//Displays a block descriptor's data
void printBlockDescriptor(BLOCKDESCRIPTOR blockDescriptor) {
     cout << "bg_block_bitmap = " << blockDescriptor.bg_block_bitmap << endl;
     cout << "bg_inode_bitmap = " << blockDescriptor.bg_inode_bitmap << endl;
     cout << "bg_inode_table = " << blockDescriptor.bg_inode_table << endl;
     cout << "bg_free_blocks_count = " << blockDescriptor.bg_free_blocks_count << endl;
     cout << "bg_free_inodes_count = " << blockDescriptor.bg_free_inodes_count << endl;
     cout << "bg_used_dirs_count = " << blockDescriptor.bg_used_dirs_count << endl;
}

//Displays a SUPERBLOCK's data
void printSuperBlock(SUPERBLOCK superblock) {
     cout << "s_inodes count = " << superblock.s_inodes_count << endl;
     cout << "s_blocks_count = " << superblock.s_blocks_count << endl;
     cout << "s_r_blocks_count = " << superblock.s_r_blocks_count << endl;
     cout << "s_free_blocks_count = " << superblock.s_free_blocks_count << endl;
     cout << "s_free_inodes_count = " << superblock.s_free_inodes_count << endl;
     cout << "s_first_data_block = " << superblock.s_first_data_block << endl;
     cout << "s_log_block_size = " << superblock.s_log_block_size << endl;
     cout << "s_log_frag_size = " << superblock.s_log_frag_size << endl;
     cout << "s_blocks_per_group = " << superblock.s_blocks_per_group << endl;
     cout << "s_frags_per_group = " << superblock.s_frags_per_group << endl;
     cout << "s_inodes_per_group = " << superblock.s_inodes_per_group << endl;
     cout << "s_mtime = " << superblock.s_mtime << endl;
     cout << "s_wtime = " << superblock.s_wtime << endl;
     cout << "s_mnt_count = " << superblock.s_mnt_count << endl;
     cout << "s_magic = " << hex << superblock.s_magic << dec << endl;
     cout << "s_state = " << superblock.s_state << endl;
     cout << "s_errors = " << superblock.s_errors << endl;
     cout << "s_minor_rev_level = " << superblock.s_minor_rev_level << endl;
     cout << "s_lastcheck = " << superblock.s_lastcheck << endl;
     cout << "s_checkinterval = " << superblock.s_checkinterval << endl;
     cout << "s_creator_os = " << superblock.s_creator_os << endl;
     cout << "s_rev_level = " << superblock.s_rev_level << endl;
     cout << "s_def_resuid = " << superblock.s_def_resuid << endl;
     cout << "s_des_resgid = " << superblock.s_des_resgid << endl;

     cout << "s_first_ino = " << superblock.s_first_ino << endl;
     cout << "s_inode_size = " << superblock.s_inode_size << endl;
     cout << "s_block_group_nr = " << superblock.s_block_group_nr << endl;
     cout << "s_feature_compat = " << superblock.s_feature_compat << endl;
     cout << "s_feature_incompat = " << superblock.s_feature_incompat << endl;
     cout << "s_feature_ro_compat = " << superblock.s_feature_ro_compat << endl;
     cout << endl;
}

//Assigns a superblock's variables
void readSuperBlock(FILE * fs, SUPERBLOCK &superblock) {
     //Declarations
     int * intBuffer = new int;
     short * shortBuffer = new short;

     //Read and assign values
     fread(intBuffer,4,1,fs);
     superblock.s_inodes_count = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_blocks_count = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_r_blocks_count = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_free_blocks_count = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_free_inodes_count = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_first_data_block = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_log_block_size = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_log_frag_size = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_blocks_per_group = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_frags_per_group = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_inodes_per_group = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_mtime = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_wtime = *intBuffer;

     fread(shortBuffer,2,1,fs);
     superblock.s_mnt_count = *shortBuffer;

     fread(shortBuffer,2,1,fs);
     superblock.s_max_mnt_count = *shortBuffer;

     fread(shortBuffer,2,1,fs);
     superblock.s_magic = *shortBuffer;

     fread(shortBuffer,2,1,fs);
     superblock.s_state = *shortBuffer;

     fread(shortBuffer,2,1,fs);
     superblock.s_errors = *shortBuffer;

     fread(shortBuffer,2,1,fs);
     superblock.s_minor_rev_level = *shortBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_lastcheck = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_checkinterval = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_creator_os = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_rev_level = *intBuffer;

     fread(shortBuffer,2,1,fs);
     superblock.s_def_resuid = *shortBuffer;

     fread(shortBuffer,2,1,fs);
     superblock.s_des_resgid = *shortBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_first_ino = *intBuffer;

     fread(shortBuffer,2,1,fs);
     superblock.s_inode_size = *shortBuffer;

     fread(shortBuffer,2,1,fs);
     superblock.s_block_group_nr = *shortBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_feature_compat = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_feature_incompat = *intBuffer;

     fread(intBuffer,4,1,fs);
     superblock.s_feature_ro_compat = *intBuffer;
}

//Compares all internal values of two blockdescriptor structs
bool isBlockDescriptorRowIdentical(BLOCKDESCRIPTOR blockDescriptorRow, BLOCKDESCRIPTOR bdCopyRow, int blockGroupNumber) {
    bool errorsFound = false;

    if(blockDescriptorRow.bg_block_bitmap != bdCopyRow.bg_block_bitmap) {
        errorsFound = true;
        cout << "Error: group " << blockGroupNumber << " bg_block_bitmap" << endl;
    }
    if(blockDescriptorRow.bg_inode_bitmap != bdCopyRow.bg_inode_bitmap) {
        errorsFound = true;
        cout << "Error: group " << blockGroupNumber << " bg_inode_bitmap" << endl;
    }
    if(blockDescriptorRow.bg_inode_table != bdCopyRow.bg_inode_table) {
        errorsFound = true;
        cout << "Error: group " << blockGroupNumber << " bg_inode_table" << endl;
    }
    if(blockDescriptorRow.bg_free_blocks_count != bdCopyRow.bg_free_blocks_count) {
        errorsFound = true;
        cout << "Error: group " << blockGroupNumber << " bg_free_blocks_count" << endl;
        cout << "Original value: " << blockDescriptorRow.bg_free_blocks_count << " - Copy value:" << bdCopyRow.bg_free_blocks_count << endl;
    }
    if(blockDescriptorRow.bg_free_inodes_count != bdCopyRow.bg_free_inodes_count) {
        errorsFound = true;
        cout << "Error: group " << blockGroupNumber << " bg_free_inodes_count" << endl;
        cout << "Original value: " << blockDescriptorRow.bg_free_inodes_count << " - Copy value:" << bdCopyRow.bg_free_inodes_count << endl;
    }
    if(blockDescriptorRow.bg_used_dirs_count != bdCopyRow.bg_used_dirs_count) {
        errorsFound = true;
        cout << "Error: group " << blockGroupNumber << " bg_used_dirs_count" << endl;
        cout << "Original value: " << blockDescriptorRow.bg_used_dirs_count << " - Copy value:" << bdCopyRow.bg_used_dirs_count << endl;
    }

    return errorsFound;
}

//Compares all internal values of two superblock structs
bool isSuperBlockIdentical(SUPERBLOCK superblock, SUPERBLOCK sbCopy) {
    bool errorsFound = false;

    if(superblock.s_inodes_count != sbCopy.s_inodes_count) {
        errorsFound = true;
        cout << "Error: s_inodes_count" << endl;
    }
    if(superblock.s_blocks_count != sbCopy.s_blocks_count) {
        errorsFound = true;
        cout << "Error: s_blocks_count" << endl;
    }
    if(superblock.s_r_blocks_count != sbCopy.s_r_blocks_count) {
        errorsFound = true;
        cout << "Error: s_r_blocks_count" << endl;
    }
    /* Not needed for superblock copy validation
    if(superblock.s_free_blocks_count != sbCopy.s_free_blocks_count) {
        errorsFound = true;
        cout << "Error: s_free_blocks_count" << endl;
    }
    if(superblock.s_free_inodes_count != sbCopy.s_free_inodes_count) {
        errorsFound = true;
        cout << "Error: s_free_inodes_count" << endl;
    }
    */
    if(superblock.s_first_data_block != sbCopy.s_first_data_block) {
        errorsFound = true;
        cout << "Error: s_first_data_block" << endl;
    }
    if(superblock.s_log_block_size != sbCopy.s_log_block_size) {
        errorsFound = true;
        cout << "Error: s_log_block_size" << endl;
    }
    if(superblock.s_log_frag_size != sbCopy.s_log_frag_size) {
        errorsFound = true;
        cout << "Error: s_log_frag_size" << endl;
    }
    if(superblock.s_blocks_per_group != sbCopy.s_blocks_per_group) {
        errorsFound = true;
        cout << "Error: s_blocks_per_group" << endl;
    }
    if(superblock.s_frags_per_group != sbCopy.s_frags_per_group) {
        errorsFound = true;
        cout << "Error: s_frags_per_group" << endl;
    }
    if(superblock.s_inodes_per_group != sbCopy.s_inodes_per_group) {
        errorsFound = true;
        cout << "Error: s_inodes_per_group" << endl;
    }
    /* Not needed for superblock copy validation
    if(superblock.s_mtime != sbCopy.s_mtime) {
        errorsFound = true;
        cout << "Error: s_mtime" << endl;
    }
    if(superblock.s_wtime != sbCopy.s_wtime) {
        errorsFound = true;
        cout << "Error: s_wtime" << endl;
    }
    if(superblock.s_mnt_count != sbCopy.s_mnt_count) {
        errorsFound = true;
        cout << "Error: s_mnt_count" << endl;
    }
    */
    if(superblock.s_max_mnt_count != sbCopy.s_max_mnt_count) {
        errorsFound = true;
        cout << "Error: s_max_mnt_count" << endl;
    }
    if(superblock.s_magic != sbCopy.s_magic) {
        errorsFound = true;
        cout << "Error: s_magic" << endl;
    }
    /* Not needed for superblock copy validation
    if(superblock.s_state != sbCopy.s_state) {
        errorsFound = true;
        cout << "Error: s_state" << endl;
    }
    */
    if(superblock.s_errors != sbCopy.s_errors) {
        errorsFound = true;
        cout << "Error: s_errors" << endl;
    }
    if(superblock.s_minor_rev_level != sbCopy.s_minor_rev_level) {
        errorsFound = true;
        cout << "Error: s_minor_rev_level" << endl;
    }
    if(superblock.s_lastcheck != sbCopy.s_lastcheck) {
        errorsFound = true;
        cout << "Error: s_lastcheck" << endl;
    }
    if(superblock.s_checkinterval != sbCopy.s_checkinterval) {
        errorsFound = true;
        cout << "Error: s_checkinterval" << endl;
    }
    if(superblock.s_creator_os != sbCopy.s_creator_os) {
        errorsFound = true;
        cout << "Error: s_creator_os" << endl;
    }
    if(superblock.s_rev_level != sbCopy.s_rev_level) {
        errorsFound = true;
        cout << "Error: s_rev_level" << endl;
    }
    if(superblock.s_def_resuid != sbCopy.s_def_resuid) {
        errorsFound = true;
        cout << "Error: s_def_resuid" << endl;
    }
    if(superblock.s_des_resgid != sbCopy.s_des_resgid) {
        errorsFound = true;
        cout << "Error: s_des_resgid" << endl;
    }
    if(superblock.s_first_ino != sbCopy.s_first_ino) {
        errorsFound = true;
        cout << "Error: s_first_ino" << endl;
    }
    if(superblock.s_inode_size != sbCopy.s_inode_size) {
        errorsFound = true;
        cout << "Error: s_inode_size" << endl;
    }
    /* Not needed for superblock copy validation
    if(superblock.s_block_group_nr != sbCopy.s_block_group_nr) {
        errorsFound = true;
        cout << "Error: s_block_group_nr" << endl;
    }
    */
    if(superblock.s_feature_compat != sbCopy.s_feature_compat) {
        errorsFound = true;
        cout << "Error: s_feature_compat" << endl;
    }
    if(superblock.s_feature_incompat != sbCopy.s_feature_incompat) {
        errorsFound = true;
        cout << "Error: s_feature_incompat" << endl;
    }
    if(superblock.s_feature_ro_compat != sbCopy.s_feature_ro_compat) {
        errorsFound = true;
        cout << "Error: s_feature_ro_compat" << endl;
    }

    /* TODO
    * Check if the superblock copy's s_block_group_nr matches the block group number
    */

    return errorsFound;
}

// Determines if a number is a power of another number
bool isPowerOf(int testVal, int base) {
    double margin = .00000001;  // not sure what a sufficient margin is. tested largest int minus 1 against base 2 and it worked, so that seems to be acceptable.
    double result = log(testVal) / log(base);
    double fractionalPortion = result - floor(result);
    if (fractionalPortion < margin) {
        return true;
    }
    return false;
}

// Determines if a block is a super block
bool isSparseGroup(int blockNumber) {
    if (blockNumber == 0 || blockNumber == 1 || isPowerOf(blockNumber, 3) || isPowerOf(blockNumber, 5) || isPowerOf(blockNumber, 7)){
        return true;
    }
    return false;
}

//Loops over all block groups to check block descriptor copies
void checkBlockDescriptorCopies(FILE * fs, int totalGroups, BLOCKDESCRIPTOR blockDescriptor[]) {
    bool errorsFound = false;

    //Loop over all block groups
    for(int i = 0;i < totalGroups; i++) {
        if(isSparseGroup(i)) {
            bool sparseGroupErrors = false;
            BLOCKDESCRIPTOR bdCopy[totalGroups-1];

            //Calculate group/block descriptor table location with bytes per block * blocks per group + 1 block + size of superblock
            cout << "Sparse block group " << i << ":" << endl;
            fseek(fs, (1024*(8192*i)+1024+1024), SEEK_SET);

            //Loop over all block groups in the table copy and check against all block groups in the original table
            for (int f = 0; f < totalGroups; f++) {
                bool localErrors = false;
                if(f != 0) {
                    fseek(fs, 14, SEEK_CUR);
                }
                readBlockDescriptor(fs, bdCopy[f]);
                localErrors = isBlockDescriptorRowIdentical(blockDescriptor[f], bdCopy[f], f);
                if(localErrors) {
                    sparseGroupErrors = localErrors;
                    errorsFound = localErrors;
                }
            }

            if(!sparseGroupErrors) {
                cout << "No errors found." << endl;
            }
            cout << "\n";
        }
    }

    if(!errorsFound) {
        cout << "Block descriptor table copies OK." << "\n";
    }else {
        cout << "ERROR - Block descriptor table copies did not match." << "\n";
    }
}

//Loops over all block groups to check superblock copies
void checkSuperBlockCopies(FILE * fs, int totalGroups, SUPERBLOCK superblock) {
    bool errorsFound = false;

    //Loop over all block groups
    for(int i = 0;i < totalGroups; i++) {
        if(isSparseGroup(i)) {
            bool localErrors = false;
            SUPERBLOCK sbCopy;

            //Calculate group/superblock location with bytes per block * blocks per group + 1 block
            cout << "Block group " << i << ":" << endl;
            fseek(fs, (1024*(8192*i)+1024), SEEK_SET);
            readSuperBlock(fs, sbCopy);
            localErrors = isSuperBlockIdentical(superblock, sbCopy);
            if(!localErrors) {
                cout << "No errors found.\n\n";
            }else {
                cout << "\n";
            }
            errorsFound = localErrors;
        }
    }

    if(!errorsFound) {
        cout << "Superblock copies OK." << "\n";
    }else {
        cout << "ERROR - Superblock copies did not match." << "\n";
    }
}

// Reads all inodes in the filesystem to determine if they are a file, directory, unused, or "other" types
void readInodeFormat(FILE * fs, int totalGroups, SUPERBLOCK superblock, BLOCKDESCRIPTOR blockDescriptor[]) {
     //Declarations
    short * shortBuffer = new short;
    short currentInode;
    int counter = 0;
    int freeInodes = 0;
    int fileInodes = 0;
    int directoryInodes = 0;
    int otherInodes = 0;

    // Read in inodes for each group and determine their mode
    for (int i = 0; i < totalGroups; i++) {
        int inodeTable = blockDescriptor[i].bg_inode_table;
        int firstInode = superblock.s_first_ino;

        for (int j = 0; j < superblock.s_inodes_per_group; j++) {
            fseek(fs, ((inodeTable * 1024) + ((firstInode + j) * superblock.s_inode_size)), SEEK_SET);
            fread(shortBuffer,2,1,fs);
            counter++;
            currentInode = *shortBuffer;

            // Count the mode types
            if(currentInode == -32348) {
                 fileInodes++;
            }
            else if(currentInode == 16877) {
                 directoryInodes++;
            }
            else if(currentInode == 0) {
                 freeInodes++;
            }
            else {
                 otherInodes++;
            }
        }
    }

    // Display results
/*    cout << "Inodes read: " << counter << endl;;   // Debug information
    cout << "Free inodes: " << freeInodes << endl; // Debug information
    cout << "Other Inodes: " << otherInodes << "\n\n";   // Debug information */
    cout << "Number of existing files: " << fileInodes << endl;
    cout << "Number of existing directories: " << directoryInodes << "\n\n";
}

int main(int argc, char* argv[]) {
    //Declarations
    const char* fileName = (argv[1] == NULL) ? "test-1k.ext2" : argv[1];
    FILE * fs;                     //file pointer
    unsigned int totalFileSystemSize;
    SUPERBLOCK superblock;
    int totalGroups;

    //Open the filesystem
    fs = fopen(fileName, "rb");

    if(fs == NULL) {
        cout << "ERROR: could not open file specified!" << endl;
        return 0;
    }

    //Get filesystem size and store it into the results map
    fseek(fs, 0, SEEK_END);
    totalFileSystemSize = ftell(fs);

    //Set file seek location and read for initial superblock
    fseek(fs, 1024, SEEK_SET);
    readSuperBlock(fs, superblock);

    //Calculate blocksize
    int blockSize = (1024 << superblock.s_log_block_size);

    //Determine group number
    totalGroups = (superblock.s_blocks_count / superblock.s_blocks_per_group);

    //Declare blockDescriptor array
    BLOCKDESCRIPTOR blockDescriptor[totalGroups - 1];

    //Set file seek location and read for initial block descriptor table
    for (int f = 0; f < totalGroups; f++) {
        fseek(fs, (2048 + (f * 32)), SEEK_SET);
        readBlockDescriptor(fs, blockDescriptor[f]);
    }

    //Print results
    cout << "Superblock information from master superblock: " << endl;
    //Validate whether the magic number is correct or not
    if(superblock.s_magic == -4269) {
        cout << "Magic number: " << hex << superblock.s_magic << dec << endl;
    }else {
        cout << "ERROR - Magic number incorrect: " << hex << superblock.s_magic << dec << endl;
    }
    cout << "    Revision: " << superblock.s_rev_level << "\n\n";

    cout << "Block information: " << endl;
    cout << "  Block size: " << blockSize << " bytes" << endl;
    cout << "  Total blocks: " << superblock.s_blocks_count << endl;
    cout << "  Total free blocks: " << superblock.s_free_blocks_count << endl;
    cout << "  Firt data block: " << superblock.s_first_data_block << "\n\n";

    cout << "Inode information: " << endl;
    cout << "  Inode size: " << superblock.s_inode_size << " bytes" << endl;
    cout << "  Inodes per data block: "<< (blockSize / superblock.s_inode_size) << endl;
    cout << "  Total inodes: " << superblock.s_inodes_count << endl;
    cout << "  Total free inodes: " << superblock.s_free_inodes_count<< endl;
    cout << "  First inode: " << superblock.s_first_ino << "\n\n";

    cout << "Block group information: " << endl;
    cout << "  Number of groups: " << totalGroups << endl;
    cout << "  Blocks per group: " << superblock.s_blocks_per_group << endl;
    cout << "  Inodes per group: " << superblock.s_inodes_per_group << "\n\n";

    //Apparently this static/negligible? Cool.
    cout << "  Block map size: 1024 bytes = 1 blocks" << endl;
    cout << "  Inode map size: 256 bytes = 1 blocks" << "\n\n";

    cout << "Block descriptor offsets: " << endl;
    cout << "Group\tBlock bitmap\tInode bitmap\tInode Table\tFree blocks\tFree Inodes" << endl;
    for (int i = 0; i < totalGroups; i++) {
        cout << i << "\t" << blockDescriptor[i].bg_block_bitmap << "\t\t" <<
              blockDescriptor[i].bg_inode_bitmap << "\t\t" <<
              blockDescriptor[i].bg_inode_table << "\t\t" <<
              blockDescriptor[i].bg_free_blocks_count << "\t\t" <<
              blockDescriptor[i].bg_free_inodes_count << endl;
    }

    cout << "\nTotal filesystem size = " << totalFileSystemSize << "\n\n";

    //TODO: Free block check
    cout << "Free block check " << endl;

    cout << "Free space available: " << (blockSize * superblock.s_free_blocks_count) << " bytes , " <<
         superblock.s_free_blocks_count << " blocks\n\n";

    cout << "Space used: " << (blockSize * (superblock.s_blocks_count - superblock.s_free_blocks_count))
         << " bytes, " << (superblock.s_blocks_count - superblock.s_free_blocks_count) << " blocks\n\n";

    readInodeFormat(fs, totalGroups, superblock, blockDescriptor);

    //TODO: Free inode check
    cout << "Free inode check " << "\n\n";

    if (superblock.s_feature_ro_compat == 1) {
       cout << "Sparse superblock backups are used." << endl;
       checkSuperBlockCopies(fs, totalGroups, superblock);
       cout << endl;

       cout << "Sparse block descriptor backups are used." << endl;
       checkBlockDescriptorCopies(fs, totalGroups, blockDescriptor);
       cout << "\n\n";
    }
    else if (superblock.s_feature_ro_compat == 2) {
         cout << "Large file support, 64-bit file size.\n" << endl;
         /* TODO
         * Do all ext2 revisions including revision 1 and after have the same sparse groups?
         */
    }
    else if (superblock.s_feature_ro_compat == 4) {
         cout << "Binary tree sorted directory files.\n" << endl;
         /* TODO
          * Do all ext2 revisions including revision 1 and after have the same sparse groups?
          */
    }

    //Print test data
    //printSuperBlock(superblock);
    //printBlockDescriptor(blockDescriptor[0]);

    //Temporary, prevents immediant closing of cmd.exe in windows
    int random = 0;
    cin >> random;

    //Default return value
    return 0;
}
