import bcrypt from 'bcryptjs';

const data = {
    users: [
    {
   name:'param',
   email:'19bcs2420@gmail.com',
   password: bcrypt.hashSync('1234',8),
   isAdmin:true,
    },
    {
    name:'Steve',
    email:'steve@gmail.com',
    password:bcrypt.hashSync('1234',8),
    isAdmin:false,
    },

    ],
    products:[
        {
           
            name:'WARSAN SUIT',
            category: 'shirts',
            price:5000,
            brand:'Warsan',
            rating:10,
            description:'new mens style',
            numReviews: 30,
            status:'fire',
            countInStock:90,
            Image:'/Images/p2.jpg',

        },
        {
            
            name:'WARSAN JACKET',
            category: 'Jacket',
            price:5990,
            brand:'Warsan',
            rating:20,
            description:'new mens style',
            numReviews: 10,
            status:'fire',
            countInStock:80,
            Image:'/Images/p3.jpg',
        },
        {
            
            name:'WARSAN SHIRTS ',
            category: 'shirts',
            Image:'/Images/p9.jpg',
            price:1600,
            brand:'Warsan',
            rating:15,
            description:'new mens style',
            numReviews: 20,
            status:'fire',
            countInStock:60,
        },
        {
           
            name:'WARSAN TROUSER',
            category: 'shirts',
            Image:' /Images/p4.jpg',
            price:2950,
            brand:'Warsan',
            rating:59,
            description:'new mens style',
            numReviews: 50,
            status:'fire',
            countInStock:50,

        },
        {
           
            name:'WARSAN SWEAT SHIRT',
            category: 'Jeans',
            Image:'/Images/p6.jpg',
            price:4500,
            brand:'Warsan',
            rating:10,
            numReviews: 80,
            description:'new mens style',
            status:'fire',
            countInStock:90,
        },
        {
            
            name:'Warsan JEANS',
            category: 'Jeans',
            Image:'/Images/p7.jpg',
            price:2590,
            brand:'Warsan',
            rating:10,
            numReviews: 80,
            description:'new mens style',
            status:'fire',
            countInStock:90,
        },
        {
            
            name:'WARSAN SUIT',
            category: 'Jeans',
            Image:'/Images/p8.jpg',
            price:10000,
            brand:'Warsan',
            rating:10,
            numReviews: 80,
            description:'new mens style',
            status:'fire',
            countInStock:90,
        },
    ],
};
export default data;