% A simple application to find pennies in a given image and output there
% location. 

% Read an image from a file into a matrix. 
image = imread('Photos\large.jpg');
imshow(image)

%convert the image to a gray scale image
bw = double(double(image(:,:,1)) + double(image(:, :, 2)) + double(image(:, :, 3)))/(3*255);
imshow(bw);

% convert image to a threshold black and white image
th = 110/255;
th_image = -ones(size(bw)); % create a black image with size of bw
th_index = find(bw<th); % Finds all the index that satisfy the threshold
th_image(th_index) = 1; % Takes all the indices and assigns one to them, creating a black and white file from the gray scale. 

imshow(th_image)


% Create a mask to be used in the convolution process.
radius = 70;
ix = sqrt(2 * pi * radius^2);
cx = ix/2;
[X, Y] = meshgrid(-(cx-1):(ix-cx), -(cx-1):(ix-cx));
mask = double((X.^2 + Y.^2) <= radius^2);
mask_index = find(mask <= 0);
mask(mask_index) = -1;
imshow(mask);

% Convolve the mask over the entire image
conv_image = conv2(mask, th_image);
conv_gray = conv_image ./ 900;
imshow(conv_image)

% Find the peaks in the image
peaks_index = find(conv_image > 12000);
peaks = zeros(size(conv_image));
peaks(peaks_index) = 1;
imshow(peaks);


% Use morphological functions to find a good approximations to the center
% of the dimes
points = bwmorph(peaks, 'shrink', inf);
imshow(points)


% Print the locations of the coins
[X, Y] = find( points >= 1);

disp('The number of coins are:')
len = length(X)

disp('The <X, Y> locations are:')

for i = 1:len
    disp([num2str(X(i)), ' ', num2str(Y(i))])
end




