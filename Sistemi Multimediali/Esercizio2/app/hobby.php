<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class hobby extends Model
{
    /**
     * The attributes that are mass assignable.
     *
     * @var array
     */
    protected $fillable = [
        'name', 'description',
    ];
}
