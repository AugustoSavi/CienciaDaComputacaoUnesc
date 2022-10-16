import mongoose from 'mongoose';
const { Schema } = mongoose;

const HeroSchema = new Schema({
    name:  String,
    slug:  String,
    age:  Number
});

export const Hero = mongoose.model('hero', HeroSchema);