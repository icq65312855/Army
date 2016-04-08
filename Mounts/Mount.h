#ifndef MOUNT_H
#define MOUNT_H

class Mount {
    private:
        int maxDistance;
    public:
        Mount(int maxDistance);
        virtual ~Mount();

        int getMaxDistance();
};

#endif // MOUNT_H