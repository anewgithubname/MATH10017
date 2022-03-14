library(imager)
# load the image
img <- load.image("UoB.jpg")
img <- grayscale(img)
# plotting the image
windows()
plot(img)
# convert the image to a matrix
m <- as.matrix(img)
# print out the size of the matrix, in terms of bytes
size1 <- dim(m)[1]*dim(m)[2]*8
print(paste("size:", size1, "bytes"))

# perform SVD
UDVT <- svd(m)
U <- UDVT$u
D <- diag(UDVT$d)
V <- UDVT$v
# check the SVD correctness
norm(m - U%*%D%*%t(V), type = "F")

# reconstruct the image using truncated SVD results
nd <- 100
U2<-U[,1:nd]
D2<-D[1:nd,1:nd]
V2<-V[,1:nd]
m_2 <- U2%*%D2%*%t(V2)

# plot the compressed image
windows()
plot(as.cimg(m_2))

# compute the size of matrices required for reconstructing the image
size2 <- (dim(m)[1]*nd + nd + dim(m)[2]*nd)*8
print(paste("size:", size2, "bytes"))

print(paste("compression ratio: ", size2/size1))
print(paste("singular value proportion:", sum(UDVT$d[1:nd])/sum(UDVT$d) ))

# the compression loss
norm(m - U2%*%D2%*%t(V2), type = "F")